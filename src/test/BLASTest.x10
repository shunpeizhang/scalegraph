/* 
 *  This file is part of the ScaleGraph project (http://scalegraph.org).
 * 
 *  This file is licensed to You under the Eclipse Public License (EPL);
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *      http://www.opensource.org/licenses/eclipse-1.0.php
 * 
 *  (C) Copyright ScaleGraph Team 2011-2012.
 */
package test;

import x10.util.Team;

import org.scalegraph.test.STest;
import org.scalegraph.util.Dist2D;
import org.scalegraph.util.random.Random;
import org.scalegraph.util.MemoryChunk;
import org.scalegraph.util.DistMemoryChunk;
import org.scalegraph.util.MathAppend;
import org.scalegraph.fileread.DistributedReader;
import org.scalegraph.graph.GraphGenerator;
import org.scalegraph.graph.Graph;
import org.scalegraph.blas.DistSparseMatrix;
import org.scalegraph.blas.BLAS;
import org.scalegraph.util.Parallel;
import org.scalegraph.blas.DistDiagonalMatrix;

final class BLASTest extends STest {
	public static def main(args: Rail[String]) {
		new BLASTest().execute(args);
	}
	
	public def run(args: Rail[String]): Boolean {
		val team = Team.WORLD;
		val scale = Int.parse(args(0));
		
		val R = 1 << (MathAppend.ceilLog2(team.size()) / 2);
		val C = team.size() / R;
		val dist = Dist2D.make2D(team, R as Int, C as Int);
		
		Console.OUT.println(dist);
		Console.OUT.println("Graph generation ...");
		
		val rnd = new Random(2, 3);
		val edgelist = GraphGenerator.genRMAT(scale, 16n, 0.45, 0.15, 0.15, rnd);
		// val weight = GraphGenerator.genRandomEdgeValue(scale, 16, rnd, team);
		val weight = new DistMemoryChunk[Double](team.placeGroup(),
				() => MemoryChunk.make[Double](edgelist.src().size(), (Long) => 1.0));

		val g = Graph.make(edgelist);
		g.setEdgeAttribute("edgevalue", weight);

		Console.OUT.println("Sparse matrix construction ...");
		// undirected and outer (A is CSR)
		val A = g.createDistSparseMatrix[Double](dist, "edgevalue", false, true);
		val N = A.ids().numberOfLocalVertexes2N();
		printIdStruct(A.ids());
		printSparseMatrix(team, A);

		Console.OUT.println("Simplify ...");
		// A.simplify(true, true, (r :MemoryChunk[Double]) => MathAppend.sum(r));

		// V <- A %*% rbind(rep(1, times=N))
		val V = new DistMemoryChunk[Double](team.placeGroup(), () =>
			MemoryChunk.make[Double](N, (Long) => 1.0));

		Console.OUT.println("V <- A * rbind(rep(1, times=N))");
		BLAS.mult[Double](1.0, A, false, V, 0.0, V);
		
		DistributedReader.write("outvec-%d.txt", V);
		
		// A <- D^(-1/2) %*% A
		team.placeGroup().broadcastFlat(() => {
			val vec_ = V();
			Parallel.iter(vec_.range(), (tid :Long, r :LongRange) => {
				for(i in r) vec_(i) = Math.sqrt(1.0 / vec_(i));
			});
		});

		Console.OUT.println("A <- D^(-1/2) * A");
		BLAS.mult[Double](1.0, DistDiagonalMatrix(V), A, false, 0.0, A);
		
		// printSparseMatrix(team, A);
		
		// V <- (I - Adj) %*% rbind(rep(1, times=N))
		team.placeGroup().broadcastFlat(() => {
			val vec_ = V();
			Parallel.iter(vec_.range(), (tid :Long, r :LongRange) => {
				for(i in r) vec_(i) = 1.0;
			});
		});

		Console.OUT.println("V <- (I - Adj) * rbind(rep(1, times=N))");
		BLAS.mult[Double](-1.0, A, false , V, 1.0, V);

		Console.OUT.println("Writing output ...");
		//DistributedReader.write("outvec-%d.txt", team, V);

		Console.OUT.println("Finished !!!");
		return true;
	}
	
	
	static def printSparseMatrix(team:Team, A:DistSparseMatrix[Double]) : void {
		for(p in team.placeGroup()) at(p) {
			val offsets = A().offsets;
			val vertexes = A().vertexes;
			val values = A().values;
			Console.OUT.println("****** SparseMatrix(" + team.role()(0) + ") ******");
			Console.OUT.println(offsets);
			Console.OUT.println(vertexes);
			Console.OUT.println(values);
			Console.OUT.println("*****************************");
		}
	}
	
	static def printIdStruct(ids:org.scalegraph.graph.id.IdStruct) : void {
		Console.OUT.println("[" + ids.lgl + ", " + ids.lgc + ", " + ids.lgr + "]");
	}
}
