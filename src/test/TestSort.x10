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

import x10.compiler.Inline;
import x10.util.IndexedMemoryChunk;
import x10.util.ArrayList;
import x10.util.Timer;
import x10.util.Random;
import org.scalegraph.util.LongIndexedMemoryChunk;
import org.scalegraph.util.MathAppend;
import org.scalegraph.util.MemoryChunk;
import org.scalegraph.util.Parallel;

class Sort {
    static val debug = false;
    private static @Inline def debugln (str:String) : void {
		if (debug) {
			Console.OUT.println("" + Timer.milliTime() + ":Hash: " + here + "(" + Runtime.workerId() + ")" + str);
			Console.OUT.flush();
		}
	}

    public static def sort[T](a:MemoryChunk[T], cmp:(T,T)=>Int) {
    	finish qsort[T](a, MathAppend.ceilLog2(Runtime.NTHREADS as Long) + 1, 0L, (a.size()-1), cmp);
    }

    public static def sort[T](a:MemoryChunk[T], proc : Int, cmp:(T,T)=>Int) {
    	finish qsort[T](a, proc, 0L, (a.size()-1), cmp);
    }

    static @Inline def qsort[T](a:MemoryChunk[T], proc: Int, lo:Long, hi:Long, cmp:(T,T)=>Int) {
    	if (hi <= lo) return;
    	var l:Long = lo;
    	var h:Long = hi;
    	val pivot = a((l+h)/2); // If we use k(hi), sorting an almost sorted array results stack overflow !!
    	while (true) {
    		while (cmp(a(l), pivot)<0) ++l;
    		while (cmp(pivot, a(h))<0) --h;
    		if (l >= h) break;
    		exch(a, l++, h--);
    	}
    	if(l == h) { ++l; --h; }
    	val ll = l;
    	val hh = h;
    	if (proc > 0) {
    		async qsort[T](a, proc - 1, lo, hh, cmp);
    		qsort[T](a, proc - 1, ll, hi, cmp);
    	} else {
    		qsort[T](a, proc - 1, lo, hh, cmp);
    		qsort[T](a, proc - 1, ll, hi, cmp);
    	}
    }
    private static @Inline def exch[T](a:MemoryChunk[T], i:Long, j:Long):void {
    	val temp = a(i);
    	a(i) = a(j);
    	a(j) = temp;
    }

}

public class TestSort {
    private static def print(str:String) {
        Console.OUT.println(str);
        Console.OUT.flush();
    }
    private static def runtest(n : Int, m : Int) {
        val a1 = new MemoryChunk[Int](n);
        val a2 = new MemoryChunk[Int](n);

        var seq : Double = 0.0;
        var par : Double = 0.0;

        for (seed in (1L..10L)) {
            val r = new Random(seed);

            for (i in a1.range()) {
                a1(i) = r.nextInt();
                a2(i) = a1(i);
            }
            {
                val start = Timer.nanoTime();
                Sort.sort(a2, m, (v1 : Int, v2 : Int)=>(v1.compareTo(v2)));
                seq += (Timer.nanoTime() - start) / (1000. * 1000. * 1000.);
            }
            {
                val start = Timer.nanoTime();
                Parallel.sort(a1, m, (v1 : Int, v2 : Int)=>(v1.compareTo(v2)));
                par += (Timer.nanoTime() - start) / (1000. * 1000. * 1000.);
            }

            for (i in a1.range()) {
                if (i != 0L) {
                    assert(a1(i - 1) <= a1(i));
                    assert(a2(i - 1) <= a2(i));
                }
                assert(a1(i) == a2(i));
            }
        }
        Console.OUT.printf("seq = %f\n", seq / 10);
        Console.OUT.printf("par = %f\n", par / 10);
    }

    public static def main(args:Array[String](1)) {
        val n = Int.parse(args(0));
        val m = Int.parse(args(1));

        runtest(n, m);
    }
}
