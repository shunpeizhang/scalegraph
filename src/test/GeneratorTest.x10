/* 
 *  This file is part of the ScaleGraph project (https://sites.google.com/site/scalegraph/).
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
import org.scalegraph.util.random.Random;
import org.scalegraph.graph.GraphGenerator;
import org.scalegraph.graph.Graph;
import org.scalegraph.harness.sx10Test;
import org.scalegraph.fileread.DistributedReader;
import org.scalegraph.util.Dist2D;

public class GeneratorTest extends sx10Test {
	
	private static def rmat_test() {
		val team = Team.WORLD;
		val rnd = new Random(2,3);
		val rmatEdges = GraphGenerator.genRMAT(14, 16, 0.45, 0.15, 0.15, rnd, team);
		DistributedReader.write("rmat-%d", team, rmatEdges);
		Console.OUT.println("rmat: done");
	}
	
	private static def erdos_test() {
	    val team = Team.WORLD;
	    val rnd = new Random(2,3);
	    val rmatEdges = GraphGenerator.genRandomGraph(14, 16, rnd, team);
	    //val rmatEdges = GraphGenerator.genRMAT(14, 16, 0.45, 0.15, 0.15, rnd, team);
	    DistributedReader.write("erdos-%d", team, rmatEdges);
	    /*
	     * val graph = new Graph(team, Graph.VertexType.Long, true);
	     * graph.addEdges(rmatEdges);
	     * val dist = Dist2D.make1D(team, Dist2D.DISTRIBUTE_COLUMNS);
	     * val matrix = graph.constructDistSparseMatrix(dist, true, true);
	     */
	    Console.OUT.println("erdos: done");
	}
	
	private static def random_test() {
		val rnd = new Random(2, 3);
		for(i in 0..1000) {
			Console.OUT.println(rnd.nextFloat());
		}
	}
	
	public static def main(args: Array[String](1)) {
		val t = new GeneratorTest();
		t.execute();
	}
	
	public def run(): Boolean {
	    rmat_test();
	    erdos_test();
	    random_test();
	    return true;
	}
}
