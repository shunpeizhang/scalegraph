package org.scalegraph.metrics;

import x10.array.RemoteArray;
import x10.compiler.Ifndef;
import x10.compiler.Inline;
import org.scalegraph.fileread.DistributedReader;
import x10.io.SerialData;
import x10.util.ArrayList;
import x10.util.IndexedMemoryChunk;
import x10.util.concurrent.AtomicLong;
import x10.util.concurrent.Lock;
import x10.util.GrowableIndexedMemoryChunk;
import x10.util.Team;
import org.scalegraph.concurrent.Dist2D;
import org.scalegraph.concurrent.Parallel;
import org.scalegraph.fileread.DistributedReader;
import org.scalegraph.graph.DistSparseMatrix;
import org.scalegraph.graph.Graph;
import org.scalegraph.graph.SparseMatrix;
import org.scalegraph.util.tuple.*;
import org.scalegraph.util.DistMemoryChunk;
import org.scalegraph.util.MathAppend;
import org.scalegraph.util.MemoryChunk;

public type Vertex = Long;
public type Distance = Long;

public class BetweennessCentrality implements x10.io.CustomSerialization {
    private val team: Team;
    private val lgl: Int;
    private val lgc: Int;
    private val lgr: Int;
    private val role: Int;
    private val localGraph: SparseMatrix;
    private var sources: Array[Vertex] = null;
    
    public static class LocalState {
        val _distSparseMatrix: DistSparseMatrix;
        val _currentSource: Cell[Vertex];
        val _queues: IndexedMemoryChunk[Bitmap];
        val _qPointer: Cell[Int];
        val _distanceMap: IndexedMemoryChunk[Long];
        val _visitMap: Bitmap;
        val _currentLevel: Cell[Long];
        val _numLocalVertices: Long;
        val _score: IndexedMemoryChunk[Double];
        val _sources: Array[Vertex];
        
        // Buffer for bfs
        val _NUM_TASK: Int;
        val _BUFFER_SIZE: Int;
        static val _ALIGN = 64;
        static val _CONGRUENT = false;
        
        // Bfs stuff
        val _predMap: IndexedMemoryChunk[ArrayList[Long]];
        val _successorCount: IndexedMemoryChunk[AtomicLong];
        val _pathCount: IndexedMemoryChunk[Long];
        val _dependency: IndexedMemoryChunk[Double];
                
        // Back tracking stuff
        val _updateScoreQueues: IndexedMemoryChunk[Bitmap];
        val _updateScoreQPointer: Cell[Int];
        val _numUpdate: IndexedMemoryChunk[Int];
        val _distanceLock: Lock = new Lock();
        
        // Debuging
        val numVertexVisit: AtomicLong = new AtomicLong(0);
        val numExamine: AtomicLong = new AtomicLong(0);
        val numAddPred: AtomicLong = new AtomicLong(0);
        
        protected def this(dsm: DistSparseMatrix,
                           src: Vertex,
                           srcs: Array[Vertex],
                           buffSize: Int) {
            val t = dsm.dist().allTeam();
            _distSparseMatrix = dsm;
            _currentSource = new Cell[Vertex](src);
            _sources = srcs;
            _queues = IndexedMemoryChunk.allocateUninitialized[Bitmap](2,
                            _ALIGN,
                            _CONGRUENT);
            // Create queues
            _numLocalVertices = dsm.ids().numberOfLocalVertexes();
            _queues(0) = new Bitmap(_numLocalVertices);
            _queues(1) = new Bitmap(_numLocalVertices);
            _visitMap = new Bitmap(_numLocalVertices);
            _qPointer = new Cell[Int](0);
            _currentLevel = new Cell[Long](0);
            _BUFFER_SIZE = buffSize;
            _NUM_TASK = Runtime.NTHREADS;
            
            _score = IndexedMemoryChunk.allocateZeroed[Double](
                    _numLocalVertices,
                    _ALIGN,
                    _CONGRUENT);
            _distanceMap = IndexedMemoryChunk.allocateZeroed[Long](
                    _numLocalVertices,
                    _ALIGN,
                    _CONGRUENT);
            _predMap =IndexedMemoryChunk.allocateUninitialized[ArrayList[Long]](
                    _numLocalVertices,
                    _ALIGN,
                    _CONGRUENT);
            _successorCount = IndexedMemoryChunk.allocateUninitialized[AtomicLong](
                    _numLocalVertices,
                    _ALIGN,
                    _CONGRUENT);
            _pathCount = IndexedMemoryChunk.allocateZeroed[Long](_numLocalVertices, 64, false);
            _dependency = IndexedMemoryChunk.allocateZeroed[Double](_numLocalVertices, 64, false);

            // Create queue for updating score
            _updateScoreQueues = IndexedMemoryChunk.allocateUninitialized[Bitmap](2, _ALIGN, false);
            _updateScoreQueues(0) = new Bitmap(_numLocalVertices);
            _updateScoreQueues(1) = new Bitmap(_numLocalVertices);
            _updateScoreQPointer = new Cell[Int](0);
            _numUpdate = IndexedMemoryChunk.allocateZeroed[Int](_numLocalVertices, _ALIGN, false);
            
            // Init loop
            for (i in 0..(_numLocalVertices - 1)) {
                _distanceMap(i) = 0L;
                _predMap(i) = null;
                _successorCount(i) = new AtomicLong(0);;
                _pathCount(i) = 0L;
                _numUpdate(i) = 0;
                _dependency(i) = 0D;
                _score(i) = 0D;
            }
        }
    }
    
    private val lch:PlaceLocalHandle[LocalState];
    
    private def this(lch_:PlaceLocalHandle[LocalState]) {
        // Set local state
        lch  = lch_;
        // Init fields
        val dsm = lch_()._distSparseMatrix;
        team = 	dsm.dist().allTeam();
        lgl = dsm.ids().lgl;
        lgc = dsm.ids().lgc;
        lgr = dsm.ids().lgr;
        role = team.getRole(here);
        localGraph = dsm();
    }
    
    public def this (serialData: SerialData) {
        this(serialData.data as PlaceLocalHandle[LocalState]);
    }
    
    public def serialize(): SerialData {
        return new SerialData(lch, null);
    }
    
    public static def run(g: Graph, _sources: Array[Vertex]) {
        val team = g.team();
        val places = team.placeGroup();
        // Represent directed graph as CSR
        val csr = g.constructDistSparseMatrix(
                Dist2D.make1D(team, Dist2D.DISTRIBUTE_COLUMNS),
                true,
                true);        
        // Create local state for BC
        val lsBfsBufferSize = (1 << 10);
        val firstSource = 12;
        val localState = PlaceLocalHandle.make[LocalState](places, 
                () => { 
            return (new LocalState(csr,
                    					firstSource,
                    					_sources,
                    					lsBfsBufferSize));
        });
        val bc = new BetweennessCentrality(localState);
        bc.internalRun();
    }
    
    private def internalRun() {
        var time: Long = System.currentTimeMillis();
        val placeGroup = team.placeGroup();
        finish {
            for (p in placeGroup) {
                at (p) async {
                    val sources = lch()._sources;
                    for (i in 0..(sources.size - 1)) {
                        if (i > 0) {
                            clear();
                        }
                        // Console.OUT.println("Src: " + i);
                        setLocalSource(sources(i)); team.barrier(role);
                        travelNonIncDist();     team.barrier(role);
                        countSuccessor();	      team.barrier(role);
                        addLeafNodeToUpdate();   team.barrier(role);
                        val c = team.allreduce(role, updateScoreNextQ().setBitCount(), Team.ADD);team.barrier(role);
                        backtracking(); 			team.barrier(role);
                        val t1 = lch().numVertexVisit.longValue();
                        lch().numVertexVisit.set(team.allreduce(role, t1, Team.ADD));
                        val t2 = lch().numExamine.longValue();
                        lch().numExamine.set(team.allreduce(role, t2, Team.ADD));
                        val t3 = lch().numAddPred.longValue();
                        val d = team.allreduce(role, t3, Team.ADD);
                        
                        // if (here.id == 0) {
                        //     Console.OUT.println("Add Pred: " + d);
                        //     Console.OUT.println("Sum set: " + c);
                        //     Console.OUT.println("Num visit: " + lch().numVertexVisit.longValue());
                        //     Console.OUT.println("Num examine: " + lch().numExamine.longValue());    
                        // }
                    }
                }
            }
        }
        time = System.currentTimeMillis() - time;
        print();
        
        Console.OUT.println("BC time: " + time);
    }
    
    @Inline
    public def setLocalSource(v: Vertex) {
        lch()._currentSource() = v;
    }
    
    @Inline
    private def clear() {
        lch()._visitMap.clearAll();
        nextQ().clearAll();
        currentQ().clearAll();
        updateScoreCurrentQ().clearAll();
        updateScoreNextQ().clearAll();
        for (i in 0..(lch()._numLocalVertices - 1)) {
            lch()._distanceMap(i) = 0L;
            if (lch()._predMap(i) != null)
                lch()._predMap(i).clear();
            lch()._successorCount(i).set(0);
            lch()._pathCount(i) = 0L;
            lch()._numUpdate(i) = 0;
            lch()._dependency(i) = 0D;
        }
        // Debug
        lch().numAddPred.set(0);
        lch().numVertexVisit.set(0);
        lch().numExamine.set(0);
    }

    public def isLocalVertex(orgVertex: Vertex): Boolean {
        val vertexPlace = ((1 << (lgc + lgr)) -1) & orgVertex;
        if(vertexPlace == role as Long)
            return true;
        return false;
    }
    
    @Inline
    public def OrgToLocSrc(v: Vertex) 
    = (( v & (( 1 << lgr) -1)) << lgl) | (v >> (lgr + lgc));
    
    @Inline
    public def LocSrcToOrg(v: Vertex)
    = ((((v & (( 1 << lgl) -1)) << lgc)| role) << lgr) | (v>> lgl);
    
    @Inline
    public def LocDstToOrg(v: Vertex)
    = ((((v & (( 1 << lgl) -1)) << lgc | (v >> lgl)) << lgr ) | 0);
    
    @Inline
    private def currentQ() = lch()._queues(lch()._qPointer());
    
    @Inline
    private def nextQ() = lch()._queues((lch()._qPointer() + 1) & 1);
    
    @Inline
    private def swapQ() { lch()._qPointer() = (lch()._qPointer() + 1) & 1; }
     
    @Inline
    private def updateScoreCurrentQ() = lch()._updateScoreQueues(lch()._updateScoreQPointer());
    
    @Inline
    private def updateScoreNextQ() = lch()._updateScoreQueues((lch()._updateScoreQPointer() + 1) & 1);
   
    @Inline
    private def swapUpdateScoreQ() { lch()._updateScoreQPointer() = (lch()._updateScoreQPointer() + 1) & 1; }
    
    @Inline
    public def getVertexPlace(orgVertex: Vertex): Place {
        return team.getPlace(getVertexPlaceRole(orgVertex));
    }
    
    @Inline
    public def getVertexPlaceRole(orgVertex: Vertex): Int {
        val vertexPlaceId = ((1 << (lgc + lgr)) -1) & orgVertex;
        return vertexPlaceId as Int;
    }
         
    private def travelNonIncDist() {
        val bufSize = lch()._BUFFER_SIZE;
        val numTask = lch()._NUM_TASK;
        val predBuf = new Array[Array[ArrayList[Vertex]]](numTask,
                (int) => new Array[ArrayList[Vertex]](team.size(),
                        (int) => new ArrayList[Vertex](bufSize)));
        val succBuf = new Array[Array[ArrayList[Vertex]]](numTask,
                (int) => new Array[ArrayList[Vertex]](team.size(),
                        (int) => new ArrayList[Vertex](bufSize)));
        val clearBuffer = (bufId: Int, pid: Int) => {
            predBuf(bufId)(pid).clear();
            succBuf(bufId)(pid).clear();
        };
        val _flood = (bufId: Int, pid: Int) => {
            val preds = predBuf(bufId)(pid).toArray();
            val succs = succBuf(bufId)(pid).toArray();
            val p = team.getPlace(pid);
            at (p)  {
                for(k in 0..(preds.size - 1)) {
                    val lv = lch()._currentLevel();
                    visit(preds(k), succs(k), lv);
                }
            }
            clearBuffer(bufId, pid);
        };
        val _floodAll = () => {
            finish for (i in 0..(numTask -1))
                async for (ii in 0..(team.size() -1)) {
                    if (predBuf(i)(ii).size() > 0)
                        _flood(i, ii);
                }
        };
        val _visitRemote = (bufId: Int, pid: Int, pred: Vertex, succ: Vertex) => {
            if (predBuf(bufId)(pid).size() >= bufSize) {  
                _flood(bufId, pid);
            } 
            predBuf(bufId)(pid).add(pred);
            succBuf(bufId)(pid).add(succ);
        };
        // Putsource
        val src = lch()._currentSource();
        if (isLocalVertex(src)) {
            val locSrc = OrgToLocSrc(src);
            nextQ().set(locSrc);
            lch()._visitMap.set(locSrc);
            lch()._distanceMap(locSrc) = 0;
        }
        if (here.id == 0)
        	Console.OUT.println("Start BFS");
        // Start traveling
        while(true) {
            swapQ();
            nextQ().clearAll();
            // Check wether vertex is available
            val maxVertexCount = team.allreduce(role,
                    currentQ().setBitCount(),
                    Team.MAX);
            if (maxVertexCount == 0L)
                break;
            val traverse = (localSrc: Vertex, threadId: Int) => {           
                val neighbors = localGraph.adjacency(localSrc);
                val predDistance = lch()._distanceMap(localSrc);
                val orgSrc = LocSrcToOrg(localSrc);                               
                for(i in neighbors.range()) {
                    lch().numExamine.incrementAndGet();
                    val orgDst = LocDstToOrg(neighbors(i));
                    if (isLocalVertex(orgDst))  {
                        visit(orgSrc, orgDst, predDistance);
                    } else {
                        val bufId = threadId;
                        val p: Place = getVertexPlace(orgDst);
                        _visitRemote(bufId, team.getRole(p), orgSrc, orgDst);
                    }    
                }
            };
            currentQ().examine(traverse);
            _floodAll();
            team.barrier(role);
            lch()._currentLevel(lch()._currentLevel() + 1);
        }
    }
    
    public atomic def visit(orgSrc: Long, orgDst: Long, predDistance: Long) {
        val localDst = OrgToLocSrc(orgDst);
        val d = predDistance + 1;
        val f = () => {
            {   
                var predMap: ArrayList[Long] = lch()._predMap(localDst);
                if (predMap == null) {
                    lch()._predMap(localDst)  = new ArrayList[Long]();;
                    predMap = lch()._predMap(localDst);
                }
                // Add predecessor
                predMap.add(orgSrc);
                // Increase path count
                lch()._pathCount(localDst) = lch()._pathCount(localDst) + 1;
                lch().numVertexVisit.incrementAndGet();
            }
        };
        if (lch()._visitMap.isNotSetAndMark(localDst)) {
            // First visit
            nextQ().set(localDst);
            lch()._distanceLock.lock();
            lch()._distanceMap(localDst) = d;
            lch()._distanceLock.unlock();
        }         
        if (lch()._distanceMap(localDst) == d){
            // Another shortest path
            f();
        }
    }
    
    private def countSuccessor() {
        if (here.id == 0)
            Console.OUT.println("Count Successor");
        val bufSize = lch()._BUFFER_SIZE;
        val numTask = lch()._NUM_TASK;
        val predBuf = new Array[Array[ArrayList[Vertex]]](numTask,
                (int) => new Array[ArrayList[Vertex]](team.size(),
                        (int) => new ArrayList[Vertex](bufSize)));
        val clearBuffer = (bufId: Int, pid: Int) => {
            predBuf(bufId)(pid).clear();
        };        
        val _flood = (bufId: Int, pid: Int) => {
            val preds = predBuf(bufId)(pid).toArray();
            val p = team.getPlace(pid);
            at (p) {
                for(k in 0..(preds.size - 1)) {
                    val pred = preds(k);
                    val locPred = OrgToLocSrc(pred);
                    lch()._successorCount(locPred).incrementAndGet();
                    lch().numAddPred.incrementAndGet();
                }
            }
            clearBuffer(bufId, pid);
        };
        val _floodAll = () => {
            finish for (i in 0..(numTask -1)) {
                val taskId = i;
                async for (ii in 0..(team.size() -1)) {
                    if (predBuf(i)(ii).size() > 0)
                        _flood(taskId, ii);
                }
            }
        };
        val addRemote = (bufId: Int, pid: Int, pred: Vertex) => {
            if (predBuf(bufId)(pid).size() >= bufSize) {  
                _flood(bufId, pid);
            }    
            predBuf(bufId)(pid).add(pred);
        };
        val examine = (i: Long, threadId: Int) => {
            if (lch()._predMap(i) != null 
                    && lch()._predMap(i).size() > 0) {  
                val sz = lch()._predMap(i).size();
                for (k in 0..(sz -1)) {  
                    val pred = lch()._predMap(i)(k);
                    val locPred = OrgToLocSrc(pred);
                    if (isLocalVertex(pred))  {
                        lch()._successorCount(locPred).incrementAndGet();
                        lch().numAddPred.incrementAndGet();
                    } else {
                        val targetRole = team.getRole(getVertexPlace(pred));
                        addRemote(threadId, targetRole, pred);
                    }    
                }
            }   
        }; 
        iter(0..(lch()._numLocalVertices - 1), examine);
        _floodAll();
    }
    
    public def addLeafNodeToUpdate() {
        val checkNode = (i: Long, threadId: Int) => {
            if (lch()._predMap(i) != null 
                    && lch()._predMap(i).size() > 0
                    && lch()._successorCount(i).longValue() == 0L) {
                updateScoreNextQ().set(i);
            } 
        };
        iter(0..(lch()._numLocalVertices - 1), checkNode);
    }
    
    public def backtracking() {
        val bufSize = lch()._BUFFER_SIZE;
        val numTask = lch()._NUM_TASK;
        val predBuf = new Array[Array[ArrayList[Vertex]]](numTask,
                (int) => new Array[ArrayList[Vertex]](team.size(),
                        (int) => new ArrayList[Vertex](bufSize)));
        val thetaBuf = new Array[Array[ArrayList[Double]]](numTask,
                (int) => new Array[ArrayList[Double]](team.size(),
                        (int) => new ArrayList[Double](bufSize)));
        val sigmaBuf = new Array[Array[ArrayList[Long]]](numTask,
                (int) => new Array[ArrayList[Long]](team.size(),
                        (int) => new ArrayList[Long](bufSize)));
        val clearBuffer = (bufId: Int, pid: Int) => {
            predBuf(bufId)(pid).clear();
            thetaBuf(bufId)(pid).clear();
            sigmaBuf(bufId)(pid).clear();
        };
        val _flood = (bufId: Int, pid: Int) => {
            val preds = predBuf(bufId)(pid).toArray();
            val theta = thetaBuf(bufId)(pid).toArray();
            val sigma = sigmaBuf(bufId)(pid).toArray();
            val p = team.getPlace(pid);
            at (p) {
                for(k in 0..(preds.size - 1)) {
                    val pred = preds(k);
                    calDependency(theta(k), sigma(k), preds(k));
                }
            }
            clearBuffer(bufId, pid);
        };
        val _floodAll = () => {
            finish for (i in 0..(numTask -1))
                async for ( ii in 0..(team.size() -1)) {
                    if (predBuf(i)(ii).size() > 0)
                        _flood(i, ii);
                }
        };
        val calRemote = (bufId: Int, pid: Int, theta: Double, signma: Long, pred: Vertex) => {
            if (predBuf(bufId)(pid).size() >= bufSize) {  
                _flood(bufId, pid);
            } 
            thetaBuf(bufId)(pid).add(theta);
            sigmaBuf(bufId)(pid).add(signma);
            predBuf(bufId)(pid).add(pred);
        };
        if (here.id == 0) {
            Console.OUT.println("Update Score");
        }
        // Console.OUT.println(here.id + ": Set count: " + updateScoreNextQ().setBitCount());
        // Start traveling
        while(true) {
            swapUpdateScoreQ();
            updateScoreNextQ().clearAll();
            team.barrier(role);
            
            // Check wether vertex is available
            val maxVertexCount = team.allreduce(role, updateScoreCurrentQ().setBitCount(), Team.MAX);
            if (maxVertexCount == 0L)
                break;
            val traverse = (localSucc: Vertex, threadId: Int) => {           
                val predList = lch()._predMap(localSucc);
                val orgSucc = LocSrcToOrg(localSucc);
                if (predList != null && predList.size() > 0) {
                    val sz = predList.size();
                    for (i in 0..(sz -1)) {  
                        val pred = predList(i);
                        val w_sigma = lch()._pathCount(localSucc);
                        val w_theta = lch()._dependency(localSucc);
                        if (isLocalVertex(pred))  {
                            calDependency(w_theta, w_sigma, pred);
                        } else {
                            val bufId = threadId;
                            val pid = getVertexPlaceRole(pred);
                            calRemote(threadId, pid, w_theta, w_sigma, pred);
                        }    
                    }
                }
            };
            updateScoreCurrentQ().examine(traverse);
            _floodAll();
            team.barrier(role);
        }
    }
    
    public atomic def calDependency(w_theta: Double, w_sigma: Long, v: Vertex) {
        val locPred = OrgToLocSrc(v);
        val numUpdates = lch()._numUpdate(locPred) + 1;
        lch()._numUpdate(locPred) = numUpdates;
        
        val sigma = lch()._pathCount(locPred) as Double;
        val dep = lch()._dependency(locPred) + (sigma / w_sigma as Double) * (1 + w_theta);
        lch()._dependency(locPred) = dep;
        
        if(lch()._numUpdate(locPred) as Long == lch()._successorCount(locPred).longValue()) {
            if (LocSrcToOrg(locPred) != lch()._currentSource())
                lch()._score(locPred) = lch()._score(locPred) + lch()._dependency(locPred);
            updateScoreNextQ().set(locPred);
        }
        assert(lch()._successorCount(locPred).longValue() > 0 
                && lch()._numUpdate(locPred) as Long <= lch()._successorCount(locPred).longValue());
    }
   
    public def del() {
        // TODO: clear all reference
    }
    
    public @Inline static def iter(range :LongRange, func :(Long, Int) => void) {
        val size = range.max - range.min + 1;
        if (size == 0L)
            return;
        val nthreads = Math.min(Runtime.NTHREADS as Long, size);
        val chunk_size = Math.max((size + nthreads - 1) / nthreads, 1L);  
        finish for(i in 0..(nthreads-1)) {
            val i_start = range.min + i * chunk_size;
            val i_range = i_start..Math.min(range.max, i_start+chunk_size-1);
            val threadId = i as Int;
            async for(ii in i_range) {
                func(ii, threadId);
            }
        }
    }
    
    //// Debugging Part 
    public def print() {
        val places = team.placeGroup();
        
        for (p in places) {
            at (p) {
                val dat = lch()._predMap;
                for (i in 0..(dat.length() - 1)) {
                    var succCount: Long = lch()._successorCount(i).longValue();
                    var predCount: Long = -1;
                    val path = lch()._pathCount(i);
                    
                    if (dat(i) != null)
                        predCount = dat(i).size();
                    
                    // if (succCount > 0 || predCount > 0)
                    //     Console.OUT.println(LocSrcToOrg(i) + " -> " + dat(i) 
                    //             + " : " + succCount
                    //             + " : " + path);
                    // if (succCount > 0 || predCount > 0)
                    //     Console.OUT.println(LocSrcToOrg(i) + " -> " + predCount 
                    //             + " : " + succCount
                    //             + " : " + path);
                    // if (lch()._dependency(i) > 0D)
                    // 	Console.OUT.println(LocSrcToOrg(i) + " -> " +  lch()._dependency(i));
                    // if (predCount != -1L)
                    // 	Console.OUT.println(LocSrcToOrg(i) + " " + succCount);
                }
            }
        }
        
        // for (p in places) {
        //     at (p) {
        //         for (i in 0..(lch()._numLocalVertices - 1)) {
        //             val orgSrc = LocSrcToOrg(i);                               
        //             if (lch()._score(i) > 0)
        //                 Console.OUT.println(orgSrc + " " + lch()._score(i));
        //         }
        //     }
        //     
        // }
    }
    
    
    //////////////////////////////////////////

	
	public static struct Bitmap {
	    protected val bitLength: Long;
	    protected val data: IndexedMemoryChunk[Long];
	    protected val bitPerWord = 64;
	    protected val setCount: AtomicLong;
	    
	    public def this(length: Long) {
	        bitLength = length;
	        val allocSize = (bitLength >> 6) + 1; // div by 64
	        data = IndexedMemoryChunk.allocateZeroed[Long](allocSize, 64, false); 
	        // Clear bits
	        for (i in 0..(data.length() - 1))	            
	           data(i) = 0L;
	        setCount = new AtomicLong(0);
	    }
	    
	    public atomic def set(bit: Long) {
	        val bitOffset = bit & ((1L << 6) -1);
	        val wordOffset = bit >> 6;
	        val mask = (1L << (bitOffset as Int));
	        
	        @Ifndef("NO_BOUNDS_CHECKS") {
	            if(bit < 0 || bit >= bitLength)
	                throw new ArrayIndexOutOfBoundsException("bit (" + bit + ") not contained in BitMap");
	        }
	        // If it is already set
	        if (((data(wordOffset) as ULong) & mask as ULong) > 0UL)
	            throw new Exception("Bit (" + bit + ") is already set"); 	       
	        data(wordOffset) = data(wordOffset) | mask; 
	        setCount.incrementAndGet();
	    }
	    
	    public atomic def clear(bit: Long) {
	        val bitOffset = bit & ((1L << 6) -1);
	        val wordOffset = bit >> 6;
	        val mask = ~(1L << (bitOffset as Int));
	        
	        @Ifndef("NO_BOUNDS_CHECKS") {
	            if(bit < 0 || bit >= bitLength)
	                throw new ArrayIndexOutOfBoundsException("bit (" + bit + ") not contained in BitMap");
	        }
	        // If it is already clear
	        if ((data(wordOffset) | mask) == 0L)
	            throw new Exception("Bit is already cleared");
	        data(wordOffset) = data(wordOffset) & mask;
	        setCount.decrementAndGet();
	    }
	    
	    public atomic def isNotSetAndMark(bit: Long): Boolean {
	        if (isNotSet(bit)) {
	            set(bit);
	            return true;
	        } else {
	            return false;
	        }
	    }
	    
	    public def isSet(bit: Long) = !isNotSet(bit);
	    
	    public def isNotSet(bit: Long): Boolean {
	        val bitOffset = bit & ((1L << 6) -1);
	        val wordOffset = bit >> 6;
	        val mask = (1L << (bitOffset as Int));
	        return (data(wordOffset) as ULong & mask as ULong) == 0UL;
	    }
	    
	    public def examine(callback: (i: Long, threadId: Int) => void) {
	        val f = (w: Long, threadId: Int) => {
	            val word = data(w);
	            var mask: Long = 0x1;
	            var callCount: Long = 0;
	            if (word == 0L)
	                return;
	            for (var l: Long = 0; l < bitPerWord; ++l) { 
	                mask = 1L << (l as Int);
	                if (((word as ULong) & (mask as ULong)) > 0UL) {
	                    val bitPos = w * bitPerWord + l;	                    
	                    if (bitPos >= bitLength)
	                        break;	                    
	                    callback(bitPos , threadId);
	                } 
	            }
	        };
	        if (setCount.longValue() > 0)
	            iter(0..(data.length() as Long - 1), f);
	    }
	    	    
	    public def clearAll() {   
	        for (i in 0..(data.length() - 1))	            
	            data(i) = 0L;
	        setCount.set(0L);
	    }
	    
	    public def setBitCount() = setCount.longValue();
	}
}