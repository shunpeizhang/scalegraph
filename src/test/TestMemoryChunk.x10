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

import org.scalegraph.util.MemoryChunk;
import org.scalegraph.util.tuple.*;
import x10.util.Timer;
import x10.util.Random;

public class TestMemoryChunk {
	private static def printTime(start :Long) {
		Console.OUT.println("Time: " + ((Timer.nanoTime() - start) / 1000000.0) + " ms");
	}
	public static def commtest_array() {
		var start :Long = Timer.nanoTime();
		val array = new Rail[Tuple2[Double,Double]](1 << 25);
		//for([i] in array) array(i) = Tuple2[Double,Double]((i*2) as Double, (i*2+1) as Double);
		var cnt : Long = 0;
		for(i in array){
			array(cnt) = Tuple2[Double,Double]((cnt*2) as Double, (cnt*2+1) as Double);
			cnt++;
		}
		printTime(start); start = Timer.nanoTime();
		at (here.next()) {
			Console.OUT.println(array(3));
		}
		printTime(start); start = Timer.nanoTime();
		at (here.next()) {
			Console.OUT.println(array(4));
		}
		printTime(start); start = Timer.nanoTime();
		at (here.next()) {
			Console.OUT.println(array(5));
		}
		printTime(start); start = Timer.nanoTime();
		at (here.next()) {
			Console.OUT.println(array(6));
		}
		printTime(start); start = Timer.nanoTime();
		at (here.next()) {
			Console.OUT.println(array(1111));
		}
		printTime(start); start = Timer.nanoTime();
	}
	public static def commtest_mc() {
		var start :Long = Timer.nanoTime();
		val array = MemoryChunk.make[Tuple2[Double,Double]](1 << 25);
		for(i in array.range()) array(i) = Tuple2[Double,Double]((i*2) as Double, (i*2+1) as Double);
		printTime(start); start = Timer.nanoTime();
		at (here.next()) {
			Console.OUT.println(array(3));
		}
		printTime(start); start = Timer.nanoTime();
		at (here.next()) {
			Console.OUT.println(array(4));
		}
		printTime(start); start = Timer.nanoTime();
		at (here.next()) {
			Console.OUT.println(array(5));
		}
		printTime(start); start = Timer.nanoTime();
		at (here.next()) {
			Console.OUT.println(array(6));
		}
		printTime(start); start = Timer.nanoTime();
		at (here.next()) {
			Console.OUT.println(array(1111));
		}
		printTime(start); start = Timer.nanoTime();
	}
	public static def gctest_array() {
		val size = 1 << 18;
		val mask = size - 1;
		val table = new Rail[Rail[Double]](size);
		val rand = new Random(3);
		var start :Long = Timer.nanoTime();
		for(i in 0..(size*16)) {
			val next = rand.nextInt() & mask;
			table(next) = new Rail[Double](128);
		}
		printTime(start);
	}
	public static def gctest_mc() {
		val size = 1 << 18;
		val mask = size - 1;
		val table = new Rail[MemoryChunk[Double]](size);
		val rand = new Random(3);
		var start :Long = Timer.nanoTime();
		for(i in 0..(size*16)) {
			val next = rand.nextInt() & mask;
			table(next) = MemoryChunk.make[Double](128);
		}
		printTime(start);
	}
	public static def gctest_mc_cheet() {
		val size = 1 << 18;
		val mask = size - 1;
		val table = new Rail[MemoryChunk[Double]](size);
		val memory = MemoryChunk.make[Double](size*128);
		val rand = new Random(3);
		var start :Long = Timer.nanoTime();
		for(i in 0..(size*16)) {
			val next = rand.nextInt() & mask;
			table(next) = memory.subpart(next*128, 128);
		}
		printTime(start);
	}
	public static def gctest_globalref_inner() {
		val size = 1 << 10;
		val mask = size - 1;
		val table = new Rail[GlobalRef[Rail[Double]]](size);
		val rand = new Random(3);
		var start :Long = Timer.nanoTime();
		for(i in 0..(size*64)) {
			val next = rand.nextInt() & mask;
			table(next) = at(here.next()) {
				val arr = new Rail[Double](16*1024);
				//for([j] in arr) arr(j) = j as Double;
				var cnt : Long = 0;
				for(j in arr){
					arr(cnt) = cnt as Double;
					cnt++;
				}
				new GlobalRef[Rail[Double]](arr)
			};
		}
		printTime(start);
	}
	public static def gctest_globalref() {
		for(i in 0..40) {
			Console.OUT.println("" + i + " th GB");
			gctest_globalref_inner();
		}
	}
	
	public static def main(args:Rail[String]) {
		val v = Zero.get[MemoryChunk[Int]]();
		Console.OUT.println(v);
	}
}
