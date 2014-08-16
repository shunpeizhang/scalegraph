/*************************************************/
/* START of InputSplitter */
#include <org/scalegraph/io/impl/InputSplitter.h>

#include <org/scalegraph/id/ProfilingID__IO.h>
#include <x10/lang/Int.h>
#include <org/scalegraph/util/MemoryChunk.h>
#include <x10/lang/Byte.h>
#include <x10/lang/Long.h>
#include <org/scalegraph/io/FileReader.h>
#include <x10/util/Team.h>
#include <org/scalegraph/io/impl/FileNameProvider.h>
#include <x10/lang/VoidFun_0_2.h>
#include <org/scalegraph/util/GrowableMemory.h>
#include <org/scalegraph/io/impl/InputSplitter__InputSplit.h>
#include <x10/array/Array.h>
#include <x10/lang/Place.h>
#include <x10/lang/Iterator.h>
#include <org/scalegraph/util/SString.h>
#include <x10/lang/Boolean.h>
#include <x10/io/File.h>
#include <x10/lang/String.h>
#include <x10/io/IOException.h>
#include <x10/array/PlaceGroup.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/util/IndexedMemoryChunk.h>
#include <x10/array/Region.h>
#include <org/scalegraph/io/impl/InputSplitter__SplitterContext.h>
#include <x10/lang/CheckedThrowable.h>
#ifndef ORG_SCALEGRAPH_IO_IMPL_INPUTSPLITTER__CLOSURE__1_CLOSURE
#define ORG_SCALEGRAPH_IO_IMPL_INPUTSPLITTER__CLOSURE__1_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class org_scalegraph_io_impl_InputSplitter__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<org_scalegraph_io_impl_InputSplitter__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void __apply() {
        
        //#line 249 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Try_c
        try {
            
            //#line 250 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
            x10_int role = (__extension__ ({
                
                //#line 250 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                x10::array::Array<x10_int>* this129005 = x10aux::nullCheck(team)->role();
                
                //#line 453 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/array/Array.x10": polyglot.ast.Empty_c
                ;
                
                //#line 452 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/array/Array.x10": x10.ast.X10LocalDecl_c
                x10_int ret129006;
                
                //#line 452 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/array/Array.x10": polyglot.ast.Labeled_c
                goto __ret129007; __ret129007: {
                {
                    
                    //#line 454 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/array/Array.x10": x10.ast.X10If_c
                    if (x10aux::nullCheck(this129005)->FMGL(rail)) {
                        
                        //#line 456 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/array/Array.x10": Eval of x10.ast.X10LocalAssign_c
                        ret129006 = (x10aux::nullCheck(this129005)->FMGL(raw))->__apply(((x10_int)0));
                        
                        //#line 456 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/array/Array.x10": polyglot.ast.Branch_c
                        goto __ret129007_end_;
                    } else {
                        
                        //#line 458 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/array/Array.x10": x10.ast.X10If_c
                        if (true && !(x10aux::nullCheck(this129005)->FMGL(region)->contains(
                                        ((x10_int)0)))) {
                            
                            //#line 459 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/array/Array.x10": Eval of x10.ast.X10Call_c
                            x10::array::Array<void>::raiseBoundsError(
                              ((x10_int)0));
                        }
                        
                        //#line 461 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/array/Array.x10": Eval of x10.ast.X10LocalAssign_c
                        ret129006 = (x10aux::nullCheck(this129005)->
                                       FMGL(raw))->__apply(((x10_int) ((((x10_int)0)) - (x10aux::nullCheck(this129005)->
                                                                                           FMGL(layout_min0)))));
                        
                        //#line 461 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/array/Array.x10": polyglot.ast.Branch_c
                        goto __ret129007_end_;
                    }
                    
                }goto __ret129007_end_; __ret129007_end_: ;
                }
                ret129006;
                }))
                ;
                
            
            //#line 251 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
            x10_long splits_begin = (__extension__ ({
                
                //#line 352 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/lang/Math.x10": x10.ast.X10LocalDecl_c
                x10_long a129008 = ((x10_long) ((((x10_long) (role))) * (splits_per_place)));
                
                //#line 352 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/lang/Math.x10": x10.ast.X10LocalDecl_c
                x10_long b129009 = (__extension__ ({
                    splits->FMGL(size);
                }))
                ;
                ((a129008) < (b129009)) ? (a129008) : (b129009);
            }))
            ;
            
            //#line 252 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
            x10_long splits_end = (__extension__ ({
                
                //#line 352 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/lang/Math.x10": x10.ast.X10LocalDecl_c
                x10_long a129010 = ((x10_long) ((((x10_long) (((x10_int) ((role) + (((x10_int)1))))))) * (splits_per_place)));
                
                //#line 352 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/lang/Math.x10": x10.ast.X10LocalDecl_c
                x10_long b129011 = (__extension__ ({
                    splits->FMGL(size);
                }))
                ;
                ((a129010) < (b129011)) ? (a129010) : (b129011);
            }))
            ;
            
            //#line 253 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
            org::scalegraph::util::MemoryChunk<org::scalegraph::io::impl::InputSplitter__InputSplit> splits_here =
              splits->org::scalegraph::util::GrowableMemory<org::scalegraph::io::impl::InputSplitter__InputSplit>::raw()->org::scalegraph::util::MemoryChunk<org::scalegraph::io::impl::InputSplitter__InputSplit>::subpart(
                splits_begin, ((x10_long) ((splits_end) - (splits_begin))));
            
            //#line 255 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
            (__extension__ ({
                
                //#line 255 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                org::scalegraph::io::impl::InputSplitter__SplitterContext* alloc127445 =
                   ((new (memset(x10aux::alloc<org::scalegraph::io::impl::InputSplitter__SplitterContext>(), 0, sizeof(org::scalegraph::io::impl::InputSplitter__SplitterContext))) org::scalegraph::io::impl::InputSplitter__SplitterContext()))
                ;
                
                //#line 255 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10ConstructorCall_c
                (alloc127445)->::org::scalegraph::io::impl::InputSplitter__SplitterContext::_constructor(
                  saved_this, splits_here, parse, nthreads);
                alloc127445;
            }))
            ->split();
            }
            catch (x10::lang::CheckedThrowable* __exc1548) {
                if (true) {
                    x10::lang::CheckedThrowable* e = static_cast<x10::lang::CheckedThrowable*>(__exc1548);
                    {
                        
                        //#line 256 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                        (e)->printStackTrace();
                    }
                } else
                throw;
            }
        }
        
        // captured environment
        x10::util::Team* team;
        x10_long splits_per_place;
        org::scalegraph::util::GrowableMemory<org::scalegraph::io::impl::InputSplitter__InputSplit>* splits;
        org::scalegraph::io::impl::InputSplitter* saved_this;
        x10::lang::VoidFun_0_2<x10_int, org::scalegraph::util::MemoryChunk<x10_byte> >* parse;
        x10_int nthreads;
        
        x10aux::serialization_id_t _get_serialization_id() {
            return _serialization_id;
        }
        
        void _serialize_body(x10aux::serialization_buffer &buf) {
            buf.write(this->team);
            buf.write(this->splits_per_place);
            buf.write(this->splits);
            buf.write(this->saved_this);
            buf.write(this->parse);
            buf.write(this->nthreads);
        }
        
        template<class __T> static __T* _deserialize(x10aux::deserialization_buffer &buf) {
            org_scalegraph_io_impl_InputSplitter__closure__1* storage = x10aux::alloc<org_scalegraph_io_impl_InputSplitter__closure__1>();
            buf.record_reference(storage);
            x10::util::Team* that_team = buf.read<x10::util::Team*>();
            x10_long that_splits_per_place = buf.read<x10_long>();
            org::scalegraph::util::GrowableMemory<org::scalegraph::io::impl::InputSplitter__InputSplit>* that_splits = buf.read<org::scalegraph::util::GrowableMemory<org::scalegraph::io::impl::InputSplitter__InputSplit>*>();
            org::scalegraph::io::impl::InputSplitter* that_saved_this = buf.read<org::scalegraph::io::impl::InputSplitter*>();
            x10::lang::VoidFun_0_2<x10_int, org::scalegraph::util::MemoryChunk<x10_byte> >* that_parse = buf.read<x10::lang::VoidFun_0_2<x10_int, org::scalegraph::util::MemoryChunk<x10_byte> >*>();
            x10_int that_nthreads = buf.read<x10_int>();
            org_scalegraph_io_impl_InputSplitter__closure__1* this_ = new (storage) org_scalegraph_io_impl_InputSplitter__closure__1(that_team, that_splits_per_place, that_splits, that_saved_this, that_parse, that_nthreads);
            return this_;
        }
        
        org_scalegraph_io_impl_InputSplitter__closure__1(x10::util::Team* team, x10_long splits_per_place, org::scalegraph::util::GrowableMemory<org::scalegraph::io::impl::InputSplitter__InputSplit>* splits, org::scalegraph::io::impl::InputSplitter* saved_this, x10::lang::VoidFun_0_2<x10_int, org::scalegraph::util::MemoryChunk<x10_byte> >* parse, x10_int nthreads) : team(team), splits_per_place(splits_per_place), splits(splits), saved_this(saved_this), parse(parse), nthreads(nthreads) { }
        
        static const x10aux::serialization_id_t _serialization_id;
        
        static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
        virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
        
        x10::lang::String* toString() {
            return x10aux::makeStringLit(this->toNativeString());
        }
        
        const char* toNativeString() {
            return "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10:248-258";
        }
    
    };
    
    #endif // ORG_SCALEGRAPH_IO_IMPL_INPUTSPLITTER__CLOSURE__1_CLOSURE
     /* private static type IO = org.scalegraph.id.ProfilingID$IO; */ 

//#line 29 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10FieldDecl_c
x10_int org::scalegraph::io::impl::InputSplitter::FMGL(T_CHUNK_SIZE);
void org::scalegraph::io::impl::InputSplitter::FMGL(T_CHUNK_SIZE__do_init)() {
    FMGL(T_CHUNK_SIZE__status) = x10aux::StaticInitController::INITIALIZING;
    _SI_("Doing static initialization for field: org::scalegraph::io::impl::InputSplitter.T_CHUNK_SIZE");
    x10_int __var1544__ = x10aux::class_cast_unchecked<x10_int>(((x10_int)131072));
    FMGL(T_CHUNK_SIZE) = __var1544__;
    FMGL(T_CHUNK_SIZE__status) = x10aux::StaticInitController::INITIALIZED;
}
void org::scalegraph::io::impl::InputSplitter::FMGL(T_CHUNK_SIZE__init)() {
    x10aux::StaticInitController::initField(&FMGL(T_CHUNK_SIZE__status), &FMGL(T_CHUNK_SIZE__do_init), &FMGL(T_CHUNK_SIZE__exception), "org::scalegraph::io::impl::InputSplitter.T_CHUNK_SIZE");
    
}
volatile x10aux::StaticInitController::status org::scalegraph::io::impl::InputSplitter::FMGL(T_CHUNK_SIZE__status);
x10::lang::CheckedThrowable* org::scalegraph::io::impl::InputSplitter::FMGL(T_CHUNK_SIZE__exception);

//#line 37 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c

//#line 47 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c

//#line 179 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
void org::scalegraph::io::impl::InputSplitter::split(x10::util::Team* team,
                                                     org::scalegraph::io::impl::FileNameProvider* fman,
                                                     x10_long offset,
                                                     x10_int nthreads,
                                                     x10::lang::VoidFun_0_2<x10_int, org::scalegraph::util::MemoryChunk<x10_byte> >* parse) {
    
    //#line 183 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
    org::scalegraph::util::GrowableMemory<org::scalegraph::io::impl::InputSplitter__InputSplit>* splits =
       ((new (memset(x10aux::alloc<org::scalegraph::util::GrowableMemory<org::scalegraph::io::impl::InputSplitter__InputSplit> >(), 0, sizeof(org::scalegraph::util::GrowableMemory<org::scalegraph::io::impl::InputSplitter__InputSplit>))) org::scalegraph::util::GrowableMemory<org::scalegraph::io::impl::InputSplitter__InputSplit>()))
    ;
    
    //#line 28 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/util/GrowableMemory.x10": x10.ast.X10ConstructorCall_c
    (splits)->::org::scalegraph::util::GrowableMemory<org::scalegraph::io::impl::InputSplitter__InputSplit>::_constructor(
      ((x10_long)0ll));
    
    //#line 185 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
    x10::array::Array<x10::lang::Place>* places = x10aux::nullCheck(team)->places();
    
    //#line 186 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
    x10_int teamSize = x10aux::nullCheck(team)->size();
    
    //#line 187 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
    x10_long numSplit = ((x10_long) (teamSize));
    
    //#line 189 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
    x10_long allSize = ((x10_long) (((x10_int)0)));
    
    //#line 190 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
    x10_long numFiles = ((x10_long) (((x10_int)0)));
    
    //#line 191 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.For_c
    {
        x10::lang::Iterator<org::scalegraph::util::SString>* path127484;
        for (
             //#line 191 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
             path127484 = x10aux::nullCheck(fman)->iterator();
             x10::lang::Iterator<org::scalegraph::util::SString>::hasNext(x10aux::nullCheck(path127484));
             ) {
            
            //#line 191 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
            org::scalegraph::util::SString path = x10::lang::Iterator<org::scalegraph::util::SString>::next(x10aux::nullCheck(path127484));
            
            //#line 192 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
            x10_long fileSize;
            
            //#line 193 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(numFiles, ((x10_long)0ll))))
            {
                
                //#line 194 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
                fileSize = ((x10_long) (((__extension__ ({
                                             
                                             //#line 194 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                                             x10::io::File* alloc127440 =
                                                ((new (memset(x10aux::alloc<x10::io::File>(), 0, sizeof(x10::io::File))) x10::io::File()))
                                             ;
                                             
                                             //#line 194 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10ConstructorCall_c
                                             (alloc127440)->::x10::io::File::_constructor(
                                               x10::lang::String::_make(reinterpret_cast<char*>((path).c_str()), true));
                                             alloc127440;
                                         }))
                                         ->size()) - (offset)));
                
                //#line 195 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
                if (((fileSize) < (((x10_long) (((x10_int)0))))))
                {
                    
                    //#line 196 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Throw_c
                    x10aux::throwException(x10aux::nullCheck(x10::io::IOException::_make(x10aux::makeStringLit("The first file must include whole header."))));
                }
                
            } else {
                
                //#line 200 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
                fileSize = (__extension__ ({
                               
                               //#line 200 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                               x10::io::File* alloc127441 =
                                  ((new (memset(x10aux::alloc<x10::io::File>(), 0, sizeof(x10::io::File))) x10::io::File()))
                               ;
                               
                               //#line 200 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10ConstructorCall_c
                               (alloc127441)->::x10::io::File::_constructor(
                                 x10::lang::String::_make(reinterpret_cast<char*>((path).c_str()), true));
                               alloc127441;
                           }))
                           ->size();
            }
            
            //#line 202 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
            allSize = ((x10_long) ((allSize) + (fileSize)));
            
            //#line 203 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
            numFiles = ((x10_long) ((numFiles) + (((x10_long)1ll))));
        }
    }
    
    //#line 205 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
    x10_long p_chunk_size = ((x10_long) ((((x10_long) ((((x10_long) ((allSize) + (numSplit)))) - (((x10_long) (((x10_int)1))))))) / x10aux::zeroCheck(numSplit)));
    
    //#line 206 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
    x10_boolean headerFile = true;
    
    //#line 208 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.For_c
    {
        x10::lang::Iterator<org::scalegraph::util::SString>* path127486;
        for (
             //#line 208 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
             path127486 = x10aux::nullCheck(fman)->iterator();
             x10::lang::Iterator<org::scalegraph::util::SString>::hasNext(x10aux::nullCheck(path127486));
             ) {
            
            //#line 208 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
            org::scalegraph::util::SString path = x10::lang::Iterator<org::scalegraph::util::SString>::next(x10aux::nullCheck(path127486));
            
            //#line 209 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
            x10::io::File* file =  ((new (memset(x10aux::alloc<x10::io::File>(), 0, sizeof(x10::io::File))) x10::io::File()))
            ;
            
            //#line 209 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10ConstructorCall_c
            (file)->::x10::io::File::_constructor(x10::lang::String::_make(reinterpret_cast<char*>((path).c_str()), true));
            
            //#line 210 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
            x10_long fileOffset;
            
            //#line 211 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
            if (headerFile) {
                
                //#line 212 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
                fileOffset = offset;
                
                //#line 213 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
                headerFile = false;
            } else {
                
                //#line 216 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
                fileOffset = ((x10_long) (((x10_int)0)));
            }
            
            //#line 219 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(numFiles, numSplit)))
            {
                
                //#line 223 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                splits->org::scalegraph::util::GrowableMemory<org::scalegraph::io::impl::InputSplitter__InputSplit>::add(
                  (__extension__ ({
                      
                      //#line 223 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                      org::scalegraph::io::impl::InputSplitter__InputSplit alloc127442 =
                         org::scalegraph::io::impl::InputSplitter__InputSplit::_alloc();
                      
                      //#line 56 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                      org::scalegraph::util::SString path129036 =
                        path;
                      
                      //#line 56 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                      x10_long start129037 = fileOffset;
                      
                      //#line 56 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                      x10_long end129038 = file->size();
                      
                      //#line 57 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
                      alloc127442->FMGL(path) = path129036;
                      
                      //#line 58 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
                      alloc127442->FMGL(start) = start129037;
                      
                      //#line 59 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
                      alloc127442->FMGL(end) = end129038;
                      alloc127442;
                  }))
                  );
            } else {
                
                //#line 226 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                org::scalegraph::io::FileReader* reader =
                   ((new (memset(x10aux::alloc<org::scalegraph::io::FileReader>(), 0, sizeof(org::scalegraph::io::FileReader))) org::scalegraph::io::FileReader()))
                ;
                
                //#line 226 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10ConstructorCall_c
                (reader)->::org::scalegraph::io::FileReader::_constructor(
                  path);
                
                //#line 227 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                x10_long size = file->size();
                
                //#line 228 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                x10_long start = fileOffset;
                
                //#line 229 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
                if ((x10aux::struct_equals(size, ((x10_long)0ll))))
                {
                    
                    //#line 229 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Branch_c
                    continue;
                }
                
                //#line 230 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10While_c
                while (true) {
                    
                    //#line 231 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                    x10_long remain = ((x10_long) ((size) - (start)));
                    
                    //#line 232 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
                    if (((remain) < (((x10_long) ((((x10_long) ((p_chunk_size) * (((x10_long) (((x10_int)3))))))) / x10aux::zeroCheck(((x10_long) (((x10_int)2)))))))))
                    {
                        
                        //#line 233 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                        splits->org::scalegraph::util::GrowableMemory<org::scalegraph::io::impl::InputSplitter__InputSplit>::add(
                          (__extension__ ({
                              
                              //#line 233 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                              org::scalegraph::io::impl::InputSplitter__InputSplit alloc127443 =
                                 org::scalegraph::io::impl::InputSplitter__InputSplit::_alloc();
                              
                              //#line 56 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                              org::scalegraph::util::SString path129039 =
                                path;
                              
                              //#line 56 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                              x10_long start129040 = start;
                              
                              //#line 56 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                              x10_long end129041 = size;
                              
                              //#line 57 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
                              alloc127443->FMGL(path) = path129039;
                              
                              //#line 58 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
                              alloc127443->FMGL(start) = start129040;
                              
                              //#line 59 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
                              alloc127443->FMGL(end) = end129041;
                              alloc127443;
                          }))
                          );
                        
                        //#line 234 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Branch_c
                        break;
                    }
                    
                    //#line 236 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                    reader->org::scalegraph::io::FileReader::skip(
                      p_chunk_size);
                    
                    //#line 237 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                    this->nextBreak(reader);
                    
                    //#line 238 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                    x10_long next = (__extension__ ({
                        reader->FMGL(fileOffset);
                    }))
                    ;
                    
                    //#line 239 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                    splits->org::scalegraph::util::GrowableMemory<org::scalegraph::io::impl::InputSplitter__InputSplit>::add(
                      (__extension__ ({
                          
                          //#line 239 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                          org::scalegraph::io::impl::InputSplitter__InputSplit alloc127444 =
                             org::scalegraph::io::impl::InputSplitter__InputSplit::_alloc();
                          
                          //#line 56 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                          org::scalegraph::util::SString path129042 =
                            path;
                          
                          //#line 56 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                          x10_long start129043 = start;
                          
                          //#line 56 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                          x10_long end129044 = next;
                          
                          //#line 57 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
                          alloc127444->FMGL(path) = path129042;
                          
                          //#line 58 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
                          alloc127444->FMGL(start) = start129043;
                          
                          //#line 59 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
                          alloc127444->FMGL(end) = end129044;
                          alloc127444;
                      }))
                      );
                    
                    //#line 240 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
                    start = next;
                }
                
                //#line 242 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                reader->org::scalegraph::io::FileReader::close();
            }
            
        }
    }
    
    //#line 247 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
    x10_long splits_per_place = ((x10_long) ((((x10_long) ((((x10_long) (((__extension__ ({
        splits->FMGL(size);
    }))
    ) + (((x10_long) (teamSize)))))) - (((x10_long) (((x10_int)1))))))) / x10aux::zeroCheck(((x10_long) (teamSize)))));
    
    //#line 248 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
    x10aux::nullCheck(x10aux::nullCheck(team)->placeGroup())->broadcastFlat(
      reinterpret_cast<x10::lang::VoidFun_0_0*>((new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(org_scalegraph_io_impl_InputSplitter__closure__1)))org_scalegraph_io_impl_InputSplitter__closure__1(team, splits_per_place, splits, this, parse, nthreads))));
}

//#line 26 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
org::scalegraph::io::impl::InputSplitter* org::scalegraph::io::impl::InputSplitter::org__scalegraph__io__impl__InputSplitter____this__org__scalegraph__io__impl__InputSplitter(
  ) {
    
    //#line 26 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10Return_c
    return this;
    
}

//#line 26 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10ConstructorDecl_c
void org::scalegraph::io::impl::InputSplitter::_constructor(
  ) {
    
    //#line 26 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.AssignPropertyCall_c
    
}

void org::scalegraph::io::impl::InputSplitter::_serialize_body(x10aux::serialization_buffer& buf) {
    
}

void org::scalegraph::io::impl::InputSplitter::_deserialize_body(x10aux::deserialization_buffer& buf) {
    
}

x10aux::RuntimeType org::scalegraph::io::impl::InputSplitter::rtt;
void org::scalegraph::io::impl::InputSplitter::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType** parents = NULL; 
    rtt.initStageTwo("org.scalegraph.io.impl.InputSplitter",x10aux::RuntimeType::class_kind, 0, parents, 0, NULL, NULL);
}

x10::lang::VoidFun_0_0::itable<org_scalegraph_io_impl_InputSplitter__closure__1>org_scalegraph_io_impl_InputSplitter__closure__1::_itable(&x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &org_scalegraph_io_impl_InputSplitter__closure__1::__apply, &org_scalegraph_io_impl_InputSplitter__closure__1::toString, &x10::lang::Closure::typeName);
x10aux::itable_entry org_scalegraph_io_impl_InputSplitter__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &org_scalegraph_io_impl_InputSplitter__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t org_scalegraph_io_impl_InputSplitter__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(org_scalegraph_io_impl_InputSplitter__closure__1::_deserialize<x10::lang::Reference>,x10aux::CLOSURE_KIND_NOT_ASYNC);

/* END of InputSplitter */
/*************************************************/
/*************************************************/
/* START of InputSplitter$InputSplit */
#include <org/scalegraph/io/impl/InputSplitter__InputSplit.h>

#include <x10/lang/Any.h>
#include <org/scalegraph/util/SString.h>
#include <x10/lang/Long.h>
#include <org/scalegraph/io/FileReader.h>
#include <x10/lang/String.h>
#include <x10/compiler/Native.h>
#include <x10/compiler/NonEscaping.h>
#include <x10/lang/Int.h>
#include <x10/lang/Boolean.h>
namespace org { namespace scalegraph { namespace io { namespace impl { 
class InputSplitter__InputSplit_ibox0 : public x10::lang::IBox<org::scalegraph::io::impl::InputSplitter__InputSplit> {
public:
    static x10::lang::Any::itable<InputSplitter__InputSplit_ibox0 > itable;
    x10_boolean equals(x10::lang::Any* arg0) {
        return this->value->equals(arg0);
    }
    x10_int hashCode() {
        return this->value->hashCode();
    }
    x10::lang::String* toString() {
        return this->value->toString();
    }
    x10::lang::String* typeName() {
        return this->value->typeName();
    }
    
};
x10::lang::Any::itable<InputSplitter__InputSplit_ibox0 >  InputSplitter__InputSplit_ibox0::itable(&InputSplitter__InputSplit_ibox0::equals, &InputSplitter__InputSplit_ibox0::hashCode, &InputSplitter__InputSplit_ibox0::toString, &InputSplitter__InputSplit_ibox0::typeName);
} } } } 
x10::lang::Any::itable<org::scalegraph::io::impl::InputSplitter__InputSplit >  org::scalegraph::io::impl::InputSplitter__InputSplit::_itable_0(&org::scalegraph::io::impl::InputSplitter__InputSplit::equals, &org::scalegraph::io::impl::InputSplitter__InputSplit::hashCode, &org::scalegraph::io::impl::InputSplitter__InputSplit::toString, &org::scalegraph::io::impl::InputSplitter__InputSplit::typeName);
x10aux::itable_entry org::scalegraph::io::impl::InputSplitter__InputSplit::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &org::scalegraph::io::impl::InputSplitter__InputSplit::_itable_0), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<org::scalegraph::io::impl::InputSplitter__InputSplit>())};
x10aux::itable_entry org::scalegraph::io::impl::InputSplitter__InputSplit::_iboxitables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &org::scalegraph::io::impl::InputSplitter__InputSplit_ibox0::itable), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<org::scalegraph::io::impl::InputSplitter__InputSplit>())};

//#line 52 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10FieldDecl_c

//#line 53 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10FieldDecl_c

//#line 54 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10FieldDecl_c

//#line 56 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10ConstructorDecl_c
void org::scalegraph::io::impl::InputSplitter__InputSplit::_constructor(org::scalegraph::util::SString path,
                                                                        x10_long start,
                                                                        x10_long end) {
    
    //#line 56 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.AssignPropertyCall_c
    
    //#line 57 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
    (*this)->FMGL(path) = path;
    
    //#line 58 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
    (*this)->FMGL(start) = start;
    
    //#line 59 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
    (*this)->FMGL(end) = end;
}
org::scalegraph::io::impl::InputSplitter__InputSplit org::scalegraph::io::impl::InputSplitter__InputSplit::_make(
  org::scalegraph::util::SString path, x10_long start, x10_long end)
{
    org::scalegraph::io::impl::InputSplitter__InputSplit this_; 
    this_->_constructor(path, start, end);
    return this_;
}



//#line 62 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c

//#line 64 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
org::scalegraph::io::FileReader* org::scalegraph::io::impl::InputSplitter__InputSplit::open(
  ) {
    
    //#line 66 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
    org::scalegraph::io::FileReader* reader =  ((new (memset(x10aux::alloc<org::scalegraph::io::FileReader>(), 0, sizeof(org::scalegraph::io::FileReader))) org::scalegraph::io::FileReader()))
    ;
    
    //#line 66 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10ConstructorCall_c
    (reader)->::org::scalegraph::io::FileReader::_constructor(
      (*this)->FMGL(path));
    
    //#line 67 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
    reader->org::scalegraph::io::FileReader::skip((*this)->
                                                    FMGL(start));
    
    //#line 68 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10Return_c
    return reader;
    
}

//#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
x10::lang::String* org::scalegraph::io::impl::InputSplitter__InputSplit::typeName(
  ){
    return x10aux::type_name((*this));
}

//#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
x10::lang::String* org::scalegraph::io::impl::InputSplitter__InputSplit::toString(
  ) {
    
    //#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10Return_c
    return x10::lang::String::__plus(x10::lang::String::__plus(x10::lang::String::__plus(x10::lang::String::__plus(x10::lang::String::__plus(x10::lang::String::__plus(x10aux::makeStringLit("struct org.scalegraph.io.impl.InputSplitter.InputSplit:"), x10aux::makeStringLit(" path=")), (*this)->
                                                                                                                                                                                                                                                                                             FMGL(path)), x10aux::makeStringLit(" start=")), (*this)->
                                                                                                                                                                                                                                                                                                                                               FMGL(start)), x10aux::makeStringLit(" end=")), (*this)->
                                                                                                                                                                                                                                                                                                                                                                                                FMGL(end));
    
}

//#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
x10_int org::scalegraph::io::impl::InputSplitter__InputSplit::hashCode(
  ) {
    
    //#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
    x10_int result = ((x10_int)1);
    
    //#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
    result = ((x10_int) ((((x10_int) ((((x10_int)8191)) * (result)))) + ((*this)->
                                                                           FMGL(path)->org::scalegraph::util::SString::hashCode())));
    
    //#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
    result = ((x10_int) ((((x10_int) ((((x10_int)8191)) * (result)))) + (x10aux::hash_code((*this)->
                                                                                             FMGL(start)))));
    
    //#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
    result = ((x10_int) ((((x10_int) ((((x10_int)8191)) * (result)))) + (x10aux::hash_code((*this)->
                                                                                             FMGL(end)))));
    
    //#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10Return_c
    return result;
    
}

//#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
x10_boolean org::scalegraph::io::impl::InputSplitter__InputSplit::equals(
  x10::lang::Any* other) {
    
    //#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
    if (!(x10aux::instanceof<org::scalegraph::io::impl::InputSplitter__InputSplit>(other)))
    {
        
        //#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10Return_c
    return (*this)->org::scalegraph::io::impl::InputSplitter__InputSplit::equals(
             x10aux::class_cast<org::scalegraph::io::impl::InputSplitter__InputSplit>(other));
    
}

//#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c

//#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
x10_boolean org::scalegraph::io::impl::InputSplitter__InputSplit::_struct_equals(
  x10::lang::Any* other) {
    
    //#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
    if (!(x10aux::instanceof<org::scalegraph::io::impl::InputSplitter__InputSplit>(other)))
    {
        
        //#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10Return_c
    return (*this)->org::scalegraph::io::impl::InputSplitter__InputSplit::_struct_equals(
             x10aux::class_cast<org::scalegraph::io::impl::InputSplitter__InputSplit>(other));
    
}

//#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c

//#line 51 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
void org::scalegraph::io::impl::InputSplitter__InputSplit::_serialize(org::scalegraph::io::impl::InputSplitter__InputSplit this_, x10aux::serialization_buffer& buf) {
    buf.write(this_->FMGL(path));
    buf.write(this_->FMGL(start));
    buf.write(this_->FMGL(end));
    
}

void org::scalegraph::io::impl::InputSplitter__InputSplit::_deserialize_body(x10aux::deserialization_buffer& buf) {
    FMGL(path) = buf.read<org::scalegraph::util::SString>();
    FMGL(start) = buf.read<x10_long>();
    FMGL(end) = buf.read<x10_long>();
}


x10aux::RuntimeType org::scalegraph::io::impl::InputSplitter__InputSplit::rtt;
void org::scalegraph::io::impl::InputSplitter__InputSplit::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::Any>()};
    rtt.initStageTwo("org.scalegraph.io.impl.InputSplitter.InputSplit",x10aux::RuntimeType::struct_kind, 2, parents, 0, NULL, NULL);
}

/* END of InputSplitter$InputSplit */
/*************************************************/
/*************************************************/
/* START of InputSplitter$SplitterContext */
#include <org/scalegraph/io/impl/InputSplitter__SplitterContext.h>

#include <x10/lang/Int.h>
#include <org/scalegraph/util/MemoryChunk.h>
#include <org/scalegraph/io/impl/InputSplitter__InputSplit.h>
#include <x10/lang/Byte.h>
#include <org/scalegraph/io/impl/InputSplitter.h>
#include <x10/lang/VoidFun_0_2.h>
#include <x10/util/concurrent/Monitor.h>
#include <org/scalegraph/util/GrowableMemory.h>
#include <x10/util/concurrent/Lock.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Long.h>
#include <org/scalegraph/util/MemoryChunkData.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/FinishState.h>
#include <x10/lang/CheckedThrowable.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/lang/Error.h>
#include <x10/lang/Exception.h>
#include <x10/compiler/AsyncClosure.h>
#include <x10/compiler/Finalization.h>
#include <x10/compiler/Abort.h>
#include <x10/compiler/CompilerFlags.h>
#include <x10/lang/LongRange.h>
#include <x10/lang/ArrayIndexOutOfBoundsException.h>
#include <x10/lang/String.h>
#include <x10/compiler/Ifndef.h>
#include <org/scalegraph/io/FileReader.h>
#ifndef ORG_SCALEGRAPH_IO_IMPL_INPUTSPLITTER__SPLITTERCONTEXT__CLOSURE__2_CLOSURE
#define ORG_SCALEGRAPH_IO_IMPL_INPUTSPLITTER__SPLITTERCONTEXT__CLOSURE__2_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void __apply() {
        
        //#line 123 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Try_c
        try {
            
            //#line 126 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.ClosureCall_c
            x10::lang::VoidFun_0_2<x10_int, org::scalegraph::util::MemoryChunk<x10_byte> >::__apply(x10aux::nullCheck(saved_this->
                                                                                                                        FMGL(parse)), 
              tid129020, data->org::scalegraph::util::MemoryChunk<x10_byte>::subpart(
                           start129012, ((x10_long) ((end129015) - (start129012)))));
        }
        catch (x10::lang::CheckedThrowable* __exc1563) {
            if (x10aux::instanceof<x10::lang::Error*>(__exc1563)) {
                x10::lang::Error* __lowerer__var__0__ = static_cast<x10::lang::Error*>(__exc1563);
                {
                    
                    //#line 123 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Throw_c
                    x10aux::throwException(x10aux::nullCheck(__lowerer__var__0__));
                }
            } else
            if (true) {
                x10::lang::CheckedThrowable* __lowerer__var__1__ =
                  static_cast<x10::lang::CheckedThrowable*>(__exc1563);
                {
                    
                    //#line 123 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Throw_c
                    x10aux::throwException(x10aux::nullCheck(x10::lang::Exception::ensureException(
                                                               reinterpret_cast<x10::lang::CheckedThrowable*>(__lowerer__var__1__))));
                }
            } else
            throw;
        }
    }
    
    // captured environment
    org::scalegraph::io::impl::InputSplitter__SplitterContext* saved_this;
    x10_int tid129020;
    org::scalegraph::util::MemoryChunk<x10_byte> data;
    x10_long start129012;
    x10_long end129015;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->tid129020);
        buf.write(this->data);
        buf.write(this->start129012);
        buf.write(this->end129015);
    }
    
    template<class __T> static __T* _deserialize(x10aux::deserialization_buffer &buf) {
        org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2* storage = x10aux::alloc<org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2>();
        buf.record_reference(storage);
        org::scalegraph::io::impl::InputSplitter__SplitterContext* that_saved_this = buf.read<org::scalegraph::io::impl::InputSplitter__SplitterContext*>();
        x10_int that_tid129020 = buf.read<x10_int>();
        org::scalegraph::util::MemoryChunk<x10_byte> that_data = buf.read<org::scalegraph::util::MemoryChunk<x10_byte> >();
        x10_long that_start129012 = buf.read<x10_long>();
        x10_long that_end129015 = buf.read<x10_long>();
        org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2* this_ = new (storage) org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2(that_saved_this, that_tid129020, that_data, that_start129012, that_end129015);
        return this_;
    }
    
    org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2(org::scalegraph::io::impl::InputSplitter__SplitterContext* saved_this, x10_int tid129020, org::scalegraph::util::MemoryChunk<x10_byte> data, x10_long start129012, x10_long end129015) : saved_this(saved_this), tid129020(tid129020), data(data), start129012(start129012), end129015(end129015) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10::lang::String* toString() {
        return x10aux::makeStringLit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10:123-128";
    }

};

#endif // ORG_SCALEGRAPH_IO_IMPL_INPUTSPLITTER__SPLITTERCONTEXT__CLOSURE__2_CLOSURE
#ifndef ORG_SCALEGRAPH_IO_IMPL_INPUTSPLITTER__SPLITTERCONTEXT__CLOSURE__3_CLOSURE
#define ORG_SCALEGRAPH_IO_IMPL_INPUTSPLITTER__SPLITTERCONTEXT__CLOSURE__3_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void __apply() {
        
        //#line 158 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Try_c
        try {
            
            //#line 158 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
            saved_this->subtask();
        }
        catch (x10::lang::CheckedThrowable* __exc1568) {
            if (x10aux::instanceof<x10::lang::Error*>(__exc1568)) {
                x10::lang::Error* __lowerer__var__0__ = static_cast<x10::lang::Error*>(__exc1568);
                {
                    
                    //#line 158 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Throw_c
                    x10aux::throwException(x10aux::nullCheck(__lowerer__var__0__));
                }
            } else
            if (true) {
                x10::lang::CheckedThrowable* __lowerer__var__1__ = static_cast<x10::lang::CheckedThrowable*>(__exc1568);
                {
                    
                    //#line 158 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Throw_c
                    x10aux::throwException(x10aux::nullCheck(x10::lang::Exception::ensureException(
                                                               reinterpret_cast<x10::lang::CheckedThrowable*>(__lowerer__var__1__))));
                }
            } else
            throw;
        }
    }
    
    // captured environment
    org::scalegraph::io::impl::InputSplitter__SplitterContext* saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static __T* _deserialize(x10aux::deserialization_buffer &buf) {
        org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3* storage = x10aux::alloc<org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3>();
        buf.record_reference(storage);
        org::scalegraph::io::impl::InputSplitter__SplitterContext* that_saved_this = buf.read<org::scalegraph::io::impl::InputSplitter__SplitterContext*>();
        org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3* this_ = new (storage) org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3(that_saved_this);
        return this_;
    }
    
    org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3(org::scalegraph::io::impl::InputSplitter__SplitterContext* saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10::lang::String* toString() {
        return x10aux::makeStringLit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10:158";
    }

};

#endif // ORG_SCALEGRAPH_IO_IMPL_INPUTSPLITTER__SPLITTERCONTEXT__CLOSURE__3_CLOSURE
#ifndef ORG_SCALEGRAPH_IO_IMPL_INPUTSPLITTER__SPLITTERCONTEXT__CLOSURE__4_CLOSURE
#define ORG_SCALEGRAPH_IO_IMPL_INPUTSPLITTER__SPLITTERCONTEXT__CLOSURE__4_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void __apply() {
        
        //#line 170 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Try_c
        try {
            
            //#line 170 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
            saved_this->subtask();
        }
        catch (x10::lang::CheckedThrowable* __exc1569) {
            if (x10aux::instanceof<x10::lang::Error*>(__exc1569)) {
                x10::lang::Error* __lowerer__var__0__ = static_cast<x10::lang::Error*>(__exc1569);
                {
                    
                    //#line 170 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Throw_c
                    x10aux::throwException(x10aux::nullCheck(__lowerer__var__0__));
                }
            } else
            if (true) {
                x10::lang::CheckedThrowable* __lowerer__var__1__ = static_cast<x10::lang::CheckedThrowable*>(__exc1569);
                {
                    
                    //#line 170 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Throw_c
                    x10aux::throwException(x10aux::nullCheck(x10::lang::Exception::ensureException(
                                                               reinterpret_cast<x10::lang::CheckedThrowable*>(__lowerer__var__1__))));
                }
            } else
            throw;
        }
    }
    
    // captured environment
    org::scalegraph::io::impl::InputSplitter__SplitterContext* saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static __T* _deserialize(x10aux::deserialization_buffer &buf) {
        org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4* storage = x10aux::alloc<org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4>();
        buf.record_reference(storage);
        org::scalegraph::io::impl::InputSplitter__SplitterContext* that_saved_this = buf.read<org::scalegraph::io::impl::InputSplitter__SplitterContext*>();
        org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4* this_ = new (storage) org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4(that_saved_this);
        return this_;
    }
    
    org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4(org::scalegraph::io::impl::InputSplitter__SplitterContext* saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10::lang::String* toString() {
        return x10aux::makeStringLit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10:170";
    }

};

#endif // ORG_SCALEGRAPH_IO_IMPL_INPUTSPLITTER__SPLITTERCONTEXT__CLOSURE__4_CLOSURE

//#line 26 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10FieldDecl_c

//#line 73 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10FieldDecl_c

//#line 74 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10FieldDecl_c

//#line 75 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10FieldDecl_c

//#line 76 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10FieldDecl_c

//#line 77 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10FieldDecl_c

//#line 78 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10FieldDecl_c

//#line 79 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10FieldDecl_c

//#line 81 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10ConstructorDecl_c
void org::scalegraph::io::impl::InputSplitter__SplitterContext::_constructor(
  org::scalegraph::io::impl::InputSplitter* out__, org::scalegraph::util::MemoryChunk<org::scalegraph::io::impl::InputSplitter__InputSplit> splits,
  x10::lang::VoidFun_0_2<x10_int, org::scalegraph::util::MemoryChunk<x10_byte> >* parse,
  x10_int nthreads) {
    
    //#line 26 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
    this->FMGL(out__) = out__;
    
    //#line 81 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.AssignPropertyCall_c
    
    //#line 72 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
    this->org::scalegraph::io::impl::InputSplitter__SplitterContext::__fieldInitializers127015();
    
    //#line 82 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
    this->FMGL(splits) = splits;
    
    //#line 83 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
    this->FMGL(parse) = parse;
    
    //#line 84 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
    this->FMGL(nthreads) = nthreads;
}
org::scalegraph::io::impl::InputSplitter__SplitterContext* org::scalegraph::io::impl::InputSplitter__SplitterContext::_make(
  org::scalegraph::io::impl::InputSplitter* out__, org::scalegraph::util::MemoryChunk<org::scalegraph::io::impl::InputSplitter__InputSplit> splits,
  x10::lang::VoidFun_0_2<x10_int, org::scalegraph::util::MemoryChunk<x10_byte> >* parse,
  x10_int nthreads) {
    org::scalegraph::io::impl::InputSplitter__SplitterContext* this_ = new (memset(x10aux::alloc<org::scalegraph::io::impl::InputSplitter__SplitterContext>(), 0, sizeof(org::scalegraph::io::impl::InputSplitter__SplitterContext))) org::scalegraph::io::impl::InputSplitter__SplitterContext();
    this_->_constructor(out__, splits, parse, nthreads);
    return this_;
}



//#line 87 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
void org::scalegraph::io::impl::InputSplitter__SplitterContext::cycleBuffers(
  x10_int numTasksToLaunch) {
    
    //#line 89 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
    this->FMGL(monitor)->lock();
    
    //#line 90 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10While_c
    while (((this->FMGL(numLauchTasks)) > (((x10_int)0))))
    {
        
        //#line 91 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
        this->FMGL(monitor)->await();
    }
    
    //#line 93 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
    this->FMGL(numLauchTasks) = numTasksToLaunch;
    
    //#line 94 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
    this->FMGL(monitor)->unlock();
    
    //#line 95 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
    org::scalegraph::util::GrowableMemory<x10_byte>* tmp =
      this->FMGL(backBuffer);
    
    //#line 96 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
    this->FMGL(backBuffer) = this->FMGL(frontBuffer);
    
    //#line 97 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
    this->FMGL(frontBuffer) = tmp;
}

//#line 100 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
void org::scalegraph::io::impl::InputSplitter__SplitterContext::notifySubtaskCompletion(
  ) {
    
    //#line 101 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
    this->FMGL(monitor)->lock();
    
    //#line 102 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals((__extension__ ({
                                   
                                   //#line 102 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                                   org::scalegraph::io::impl::InputSplitter__SplitterContext* x128973 =
                                     this;
                                   
                                   //#line 102 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Empty_c
                                   ;
                                   x10aux::nullCheck(x128973)->
                                     FMGL(numLauchTasks) =
                                     ((x10_int) ((x10aux::nullCheck(x128973)->
                                                    FMGL(numLauchTasks)) - (((x10_int)1))));
                               }))
                               , ((x10_int)0)))) {
        
        //#line 103 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
        this->FMGL(monitor)->release();
    } else {
        
        //#line 105 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
        this->FMGL(monitor)->unlock();
    }
    
}

//#line 108 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
void org::scalegraph::io::impl::InputSplitter__SplitterContext::subtask(
  ) {
    
    //#line 109 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Try_c
    try {
        
        //#line 112 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
        org::scalegraph::util::MemoryChunk<x10_byte> data =
          x10aux::nullCheck(this->FMGL(frontBuffer))->org::scalegraph::util::GrowableMemory<x10_byte>::raw();
        
        //#line 113 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
        x10_long size = (__extension__ ({
            data->FMGL(data)->FMGL(size);
        }))
        ;
        
        //#line 114 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
        x10_long t_chunk_size = ((x10_long) ((((x10_long) ((((x10_long) ((size) + (((x10_long) (this->
                                                                                                  FMGL(nthreads))))))) - (((x10_long) (((x10_int)1))))))) / x10aux::zeroCheck(((x10_long) (this->
                                                                                                                                                                                             FMGL(nthreads))))));
        
        //#line 115 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
        x10_long offset = ((x10_long) (((x10_int)0)));
        {
            
            //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
            x10::lang::Runtime::ensureNotInAtomic();
            
            //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
            x10::lang::FinishState* x10____var144 = x10::lang::Runtime::startFinish();
            {
                
                //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                x10::lang::CheckedThrowable* throwable129055 =
                  x10aux::class_cast_unchecked<x10::lang::CheckedThrowable*>(X10_NULL);
                
                //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Try_c
                try {
                    
                    //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Try_c
                    try {
                        {
                            
                            //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                            x10_int i127447max129018 = ((x10_int) ((this->
                                                                      FMGL(nthreads)) - (((x10_int)1))));
                            
                            //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.For_c
                            {
                                x10_int i129019;
                                for (
                                     //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                                     i129019 = ((x10_int)0);
                                     ((i129019) <= (i127447max129018));
                                     
                                     //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
                                     i129019 = ((x10_int) ((i129019) + (((x10_int)1)))))
                                {
                                    
                                    //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                                    x10_int tid129020 = i129019;
                                    
                                    //#line 119 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                                    x10_long start129012 =
                                      (__extension__ ({
                                        
                                        //#line 352 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/lang/Math.x10": x10.ast.X10LocalDecl_c
                                        x10_long a129013 =
                                          offset;
                                        
                                        //#line 352 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/lang/Math.x10": x10.ast.X10LocalDecl_c
                                        x10_long b129014 =
                                          size;
                                        ((a129013) < (b129014))
                                          ? (a129013) : (b129014);
                                    }))
                                    ;
                                    
                                    //#line 120 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                                    x10_long end129015 = x10aux::nullCheck(this->
                                                                             FMGL(out__))->nextBreak(
                                                           data,
                                                           (__extension__ ({
                                                               
                                                               //#line 352 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/lang/Math.x10": x10.ast.X10LocalDecl_c
                                                               x10_long a129016 =
                                                                 ((x10_long) ((offset) + (t_chunk_size)));
                                                               
                                                               //#line 352 "/usr/global/x10/x10-trunk-custom/x10.dist/stdlib/x10.jar:x10/lang/Math.x10": x10.ast.X10LocalDecl_c
                                                               x10_long b129017 =
                                                                 size;
                                                               ((a129016) < (b129017))
                                                                 ? (a129016)
                                                                 : (b129017);
                                                           }))
                                                           );
                                    
                                    //#line 123 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                                    x10::lang::Runtime::runAsync(
                                      reinterpret_cast<x10::lang::VoidFun_0_0*>((new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2)))org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2(this, tid129020, data, start129012, end129015))));
                                    
                                    //#line 129 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
                                    offset = end129015;
                                }
                            }
                            
                        }
                    }
                    catch (x10::lang::CheckedThrowable* __exc1564) {
                        if (true) {
                            x10::lang::CheckedThrowable* __lowerer__var__0__ =
                              static_cast<x10::lang::CheckedThrowable*>(__exc1564);
                            {
                                
                                //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                                x10::lang::Runtime::pushException(
                                  __lowerer__var__0__);
                                
                                //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Throw_c
                                x10aux::throwException(x10aux::nullCheck(x10::lang::Exception::_make()));
                            }
                        } else
                        throw;
                    }
                    
                    //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                    x10::compiler::Finalization::plausibleThrow();
                }
                catch (x10::lang::CheckedThrowable* __exc1565) {
                    if (true) {
                        x10::lang::CheckedThrowable* formal129056 =
                          static_cast<x10::lang::CheckedThrowable*>(__exc1565);
                        {
                            
                            //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
                            throwable129055 = formal129056;
                        }
                    } else
                    throw;
                }
                
                //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
                if ((!x10aux::struct_equals(X10_NULL, throwable129055)))
                {
                    
                    //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
                    if (x10aux::instanceof<x10::compiler::Abort*>(throwable129055))
                    {
                        
                        //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Throw_c
                        x10aux::throwException(x10aux::nullCheck(throwable129055));
                    }
                    
                }
                
                //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
                if (true) {
                    
                    //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                    x10::lang::Runtime::stopFinish(x10____var144);
                }
                
                //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
                if ((!x10aux::struct_equals(X10_NULL, throwable129055)))
                {
                    
                    //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
                    if (!(x10aux::instanceof<x10::compiler::Finalization*>(throwable129055)))
                    {
                        
                        //#line 118 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Throw_c
                        x10aux::throwException(x10aux::nullCheck(throwable129055));
                    }
                    
                }
                
            }
        }
        
        //#line 133 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
        this->notifySubtaskCompletion();
    }
    catch (x10::lang::CheckedThrowable* __exc1566) {
        if (true) {
            x10::lang::CheckedThrowable* e = static_cast<x10::lang::CheckedThrowable*>(__exc1566);
            {
                
                //#line 134 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                (e)->printStackTrace();
            }
        } else
        throw;
    }
}

//#line 137 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
void org::scalegraph::io::impl::InputSplitter__SplitterContext::split(
  ) {
    
    //#line 140 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
    x10_int s_chunk_size = ((x10_int) ((((x10_int)131072)) * (this->
                                                                FMGL(nthreads))));
    {
        
        //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
        x10::lang::Runtime::ensureNotInAtomic();
        
        //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
        x10::lang::FinishState* x10____var145 = x10::lang::Runtime::startFinish();
        {
            
            //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
            x10::lang::CheckedThrowable* throwable129058 =
              x10aux::class_cast_unchecked<x10::lang::CheckedThrowable*>(X10_NULL);
            
            //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Try_c
            try {
                
                //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Try_c
                try {
                    {
                        
                        //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                        x10::lang::LongRange i127465domain129031 =
                          (__extension__ ({
                            
                            //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                            org::scalegraph::util::MemoryChunk<org::scalegraph::io::impl::InputSplitter__InputSplit> this129032 =
                              this->FMGL(splits);
                            x10::lang::LongRange::_make(((x10_long)0ll), ((x10_long) ((this129032->
                                                                                         FMGL(data)->
                                                                                         FMGL(size)) - (((x10_long)1ll)))));
                        }))
                        ;
                        
                        //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                        x10_long i127465max129033 = i127465domain129031->
                                                      FMGL(max);
                        
                        //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.For_c
                        {
                            x10_long i129034;
                            for (
                                 //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                                 i129034 = ((x10_long)0ll);
                                 ((i129034) <= (i127465max129033));
                                 
                                 //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
                                 i129034 = ((x10_long) ((i129034) + (((x10_long)1ll)))))
                            {
                                
                                //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                                x10_long sidx129035 = i129034;
                                
                                //#line 144 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                                org::scalegraph::io::impl::InputSplitter__InputSplit split129023 =
                                  (__extension__ ({
                                    
                                    //#line 144 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                                    org::scalegraph::util::MemoryChunk<org::scalegraph::io::impl::InputSplitter__InputSplit> this129024 =
                                      this->FMGL(splits);
                                    
                                    //#line 270 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/util/MemoryChunk.x10": x10.ast.X10LocalDecl_c
                                    x10_long index129025 =
                                      sidx129035;
                                    
                                    //#line 270 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/util/MemoryChunk.x10": x10.ast.X10LocalDecl_c
                                    org::scalegraph::io::impl::InputSplitter__InputSplit ret129026;
                                    {
                                        
                                        //#line 272 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/util/MemoryChunk.x10": x10.ast.X10If_c
                                        if (!((this129024->
                                                 FMGL(data)).isValid()))
                                        {
                                            
                                            //#line 273 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/util/MemoryChunk.x10": x10.ast.X10If_c
                                            if (true) {
                                                
                                                //#line 273 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/util/MemoryChunk.x10": polyglot.ast.Throw_c
                                                x10aux::throwException(x10aux::nullCheck(x10::lang::ArrayIndexOutOfBoundsException::_make(x10aux::makeStringLit("This MemoryChunk is released."))));
                                            }
                                            
                                        }
                                        
                                        //#line 274 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/util/MemoryChunk.x10": x10.ast.X10If_c
                                        if (((index129025) < (((x10_long) (((x10_int)0))))) ||
                                            ((index129025) >= (this129024->
                                                                 FMGL(data)->
                                                                 FMGL(size))))
                                        {
                                            
                                            //#line 275 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/util/MemoryChunk.x10": x10.ast.X10If_c
                                            if (true) {
                                                
                                                //#line 275 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/util/MemoryChunk.x10": polyglot.ast.Throw_c
                                                x10aux::throwException(x10aux::nullCheck(x10::lang::ArrayIndexOutOfBoundsException::_make(x10::lang::String::__plus(x10::lang::String::__plus(x10aux::makeStringLit("index ("), index129025), x10aux::makeStringLit(") not contained in MemoryChunk")))));
                                            }
                                            
                                        }
                                        
                                    }
                                    
                                    //#line 277 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/util/MemoryChunk.x10": Eval of x10.ast.X10LocalAssign_c
                                    ret129026 = (this129024->
                                                   FMGL(data))[index129025];
                                    ret129026;
                                }))
                                ;
                                
                                //#line 145 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                                org::scalegraph::io::FileReader* reader129027 =
                                  split129023->org::scalegraph::io::impl::InputSplitter__InputSplit::open();
                                
                                //#line 146 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10While_c
                                while (true) {
                                    
                                    //#line 147 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                                    x10_long start129028 =
                                      (__extension__ ({
                                        reader129027->FMGL(fileOffset);
                                    }))
                                    ;
                                    
                                    //#line 148 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                                    x10_long remain129029 =
                                      ((x10_long) ((split129023->
                                                      FMGL(end)) - (start129028)));
                                    
                                    //#line 149 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
                                    if (((remain129029) < (((x10_long) (((x10_int) ((((x10_int) ((s_chunk_size) * (((x10_int)3))))) / x10aux::zeroCheck(((x10_int)2)))))))))
                                    {
                                        
                                        //#line 150 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                                        x10aux::nullCheck(this->
                                                            FMGL(backBuffer))->org::scalegraph::util::GrowableMemory<x10_byte>::setSize(
                                          remain129029);
                                        
                                        //#line 152 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                                        reader129027->org::scalegraph::io::FileReader::read(
                                          x10aux::nullCheck(this->
                                                              FMGL(backBuffer))->org::scalegraph::util::GrowableMemory<x10_byte>::raw());
                                        
                                        //#line 154 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                                        x10aux::nullCheck(this->
                                                            FMGL(backBuffer))->org::scalegraph::util::GrowableMemory<x10_byte>::grow(
                                          ((x10_long) ((remain129029) + (((x10_long) (((x10_int)1)))))));
                                        
                                        //#line 156 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                                        this->cycleBuffers(
                                          ((x10_int)1));
                                        
                                        //#line 158 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                                        x10::lang::Runtime::runAsync(
                                          reinterpret_cast<x10::lang::VoidFun_0_0*>((new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3)))org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3(this))));
                                        
                                        //#line 159 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Branch_c
                                        break;
                                    }
                                    
                                    //#line 161 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                                    x10aux::nullCheck(this->
                                                        FMGL(backBuffer))->org::scalegraph::util::GrowableMemory<x10_byte>::setSize(
                                      ((x10_long) (s_chunk_size)));
                                    
                                    //#line 163 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                                    reader129027->org::scalegraph::io::FileReader::read(
                                      x10aux::nullCheck(this->
                                                          FMGL(backBuffer))->org::scalegraph::util::GrowableMemory<x10_byte>::raw());
                                    
                                    //#line 165 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                                    org::scalegraph::util::GrowableMemory<x10_byte>* this129021 =
                                      this->FMGL(backBuffer);
                                    
                                    //#line 68 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/util/GrowableMemory.x10": x10.ast.X10LocalDecl_c
                                    org::scalegraph::util::MemoryChunk<x10_byte> items129022 =
                                      x10aux::nullCheck(this->
                                                          FMGL(out__))->nextBreak(
                                        reader129027);
                                    
                                    //#line 69 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/util/GrowableMemory.x10": Eval of x10.ast.X10Call_c
                                    x10aux::nullCheck(this129021)->org::scalegraph::util::GrowableMemory<x10_byte>::insert(
                                      x10aux::nullCheck(this129021)->
                                        FMGL(size), items129022);
                                    
                                    //#line 166 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                                    x10aux::nullCheck(this->
                                                        FMGL(backBuffer))->org::scalegraph::util::GrowableMemory<x10_byte>::grow(
                                      ((x10_long) (((__extension__ ({
                                          
                                          //#line 166 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
                                          org::scalegraph::util::GrowableMemory<x10_byte>* this129030 =
                                            this->FMGL(backBuffer);
                                          x10aux::nullCheck(this129030)->
                                            FMGL(size);
                                      }))
                                      ) + (((x10_long) (((x10_int)1)))))));
                                    
                                    //#line 168 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                                    this->cycleBuffers(((x10_int)1));
                                    
                                    //#line 170 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                                    x10::lang::Runtime::runAsync(
                                      reinterpret_cast<x10::lang::VoidFun_0_0*>((new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4)))org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4(this))));
                                }
                                
                                //#line 172 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                                reader129027->org::scalegraph::io::FileReader::close();
                            }
                        }
                        
                    }
                }
                catch (x10::lang::CheckedThrowable* __exc1570) {
                    if (true) {
                        x10::lang::CheckedThrowable* __lowerer__var__0__ =
                          static_cast<x10::lang::CheckedThrowable*>(__exc1570);
                        {
                            
                            //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                            x10::lang::Runtime::pushException(
                              __lowerer__var__0__);
                            
                            //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Throw_c
                            x10aux::throwException(x10aux::nullCheck(x10::lang::Exception::_make()));
                        }
                    } else
                    throw;
                }
                
                //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                x10::compiler::Finalization::plausibleThrow();
            }
            catch (x10::lang::CheckedThrowable* __exc1571) {
                if (true) {
                    x10::lang::CheckedThrowable* formal129059 =
                      static_cast<x10::lang::CheckedThrowable*>(__exc1571);
                    {
                        
                        //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10LocalAssign_c
                        throwable129058 = formal129059;
                    }
                } else
                throw;
            }
            
            //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(X10_NULL, throwable129058)))
            {
                
                //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
                if (x10aux::instanceof<x10::compiler::Abort*>(throwable129058))
                {
                    
                    //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Throw_c
                    x10aux::throwException(x10aux::nullCheck(throwable129058));
                }
                
            }
            
            //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
            if (true) {
                
                //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10Call_c
                x10::lang::Runtime::stopFinish(x10____var145);
            }
            
            //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(X10_NULL, throwable129058)))
            {
                
                //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10If_c
                if (!(x10aux::instanceof<x10::compiler::Finalization*>(throwable129058)))
                {
                    
                    //#line 143 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": polyglot.ast.Throw_c
                    x10aux::throwException(x10aux::nullCheck(throwable129058));
                }
                
            }
            
        }
    }
}

//#line 72 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
org::scalegraph::io::impl::InputSplitter__SplitterContext*
  org::scalegraph::io::impl::InputSplitter__SplitterContext::org__scalegraph__io__impl__InputSplitter__SplitterContext____this__org__scalegraph__io__impl__InputSplitter__SplitterContext(
  ) {
    
    //#line 72 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10Return_c
    return this;
    
}

//#line 72 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
org::scalegraph::io::impl::InputSplitter* org::scalegraph::io::impl::InputSplitter__SplitterContext::org__scalegraph__io__impl__InputSplitter__SplitterContext____this__org__scalegraph__io__impl__InputSplitter(
  ) {
    
    //#line 72 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10Return_c
    return this->FMGL(out__);
    
}

//#line 72 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10MethodDecl_c
void org::scalegraph::io::impl::InputSplitter__SplitterContext::__fieldInitializers127015(
  ) {
    
    //#line 72 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
    this->FMGL(monitor) = x10::util::concurrent::Monitor::_make();
    
    //#line 72 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
    this->FMGL(numLauchTasks) = ((x10_int)0);
    
    //#line 72 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
    this->FMGL(frontBuffer) = (__extension__ ({
        
        //#line 78 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
        org::scalegraph::util::GrowableMemory<x10_byte>* alloc127438 =
           ((new (memset(x10aux::alloc<org::scalegraph::util::GrowableMemory<x10_byte> >(), 0, sizeof(org::scalegraph::util::GrowableMemory<x10_byte>))) org::scalegraph::util::GrowableMemory<x10_byte>()))
        ;
        
        //#line 28 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/util/GrowableMemory.x10": x10.ast.X10ConstructorCall_c
        (alloc127438)->::org::scalegraph::util::GrowableMemory<x10_byte>::_constructor(
          ((x10_long)0ll));
        alloc127438;
    }))
    ;
    
    //#line 72 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": Eval of x10.ast.X10FieldAssign_c
    this->FMGL(backBuffer) = (__extension__ ({
        
        //#line 79 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/io/impl/InputSplitter.x10": x10.ast.X10LocalDecl_c
        org::scalegraph::util::GrowableMemory<x10_byte>* alloc127439 =
           ((new (memset(x10aux::alloc<org::scalegraph::util::GrowableMemory<x10_byte> >(), 0, sizeof(org::scalegraph::util::GrowableMemory<x10_byte>))) org::scalegraph::util::GrowableMemory<x10_byte>()))
        ;
        
        //#line 28 "/nfs/home/vinodmadaan/ScaleGraph_Stable_Version/scalegraph/src/org/scalegraph/util/GrowableMemory.x10": x10.ast.X10ConstructorCall_c
        (alloc127439)->::org::scalegraph::util::GrowableMemory<x10_byte>::_constructor(
          ((x10_long)0ll));
        alloc127439;
    }))
    ;
}
const x10aux::serialization_id_t org::scalegraph::io::impl::InputSplitter__SplitterContext::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(org::scalegraph::io::impl::InputSplitter__SplitterContext::_deserializer, x10aux::CLOSURE_KIND_NOT_ASYNC);

void org::scalegraph::io::impl::InputSplitter__SplitterContext::_serialize_body(x10aux::serialization_buffer& buf) {
    buf.write(this->FMGL(nthreads));
    buf.write(this->FMGL(splits));
    buf.write(this->FMGL(parse));
    buf.write(this->FMGL(monitor));
    buf.write(this->FMGL(numLauchTasks));
    buf.write(this->FMGL(frontBuffer));
    buf.write(this->FMGL(backBuffer));
    buf.write(this->FMGL(out__));
    
}

x10::lang::Reference* org::scalegraph::io::impl::InputSplitter__SplitterContext::_deserializer(x10aux::deserialization_buffer& buf) {
    org::scalegraph::io::impl::InputSplitter__SplitterContext* this_ = new (memset(x10aux::alloc<org::scalegraph::io::impl::InputSplitter__SplitterContext>(), 0, sizeof(org::scalegraph::io::impl::InputSplitter__SplitterContext))) org::scalegraph::io::impl::InputSplitter__SplitterContext();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

void org::scalegraph::io::impl::InputSplitter__SplitterContext::_deserialize_body(x10aux::deserialization_buffer& buf) {
    FMGL(nthreads) = buf.read<x10_int>();
    FMGL(splits) = buf.read<org::scalegraph::util::MemoryChunk<org::scalegraph::io::impl::InputSplitter__InputSplit> >();
    FMGL(parse) = buf.read<x10::lang::VoidFun_0_2<x10_int, org::scalegraph::util::MemoryChunk<x10_byte> >*>();
    FMGL(monitor) = buf.read<x10::util::concurrent::Monitor*>();
    FMGL(numLauchTasks) = buf.read<x10_int>();
    FMGL(frontBuffer) = buf.read<org::scalegraph::util::GrowableMemory<x10_byte>*>();
    FMGL(backBuffer) = buf.read<org::scalegraph::util::GrowableMemory<x10_byte>*>();
    FMGL(out__) = buf.read<org::scalegraph::io::impl::InputSplitter*>();
}

x10aux::RuntimeType org::scalegraph::io::impl::InputSplitter__SplitterContext::rtt;
void org::scalegraph::io::impl::InputSplitter__SplitterContext::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType** parents = NULL; 
    rtt.initStageTwo("org.scalegraph.io.impl.InputSplitter.SplitterContext",x10aux::RuntimeType::class_kind, 0, parents, 0, NULL, NULL);
}

x10::lang::VoidFun_0_0::itable<org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2>org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2::_itable(&x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2::__apply, &org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2::toString, &x10::lang::Closure::typeName);
x10aux::itable_entry org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__2::_deserialize<x10::lang::Reference>,x10aux::CLOSURE_KIND_SIMPLE_ASYNC);

x10::lang::VoidFun_0_0::itable<org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3>org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3::_itable(&x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3::__apply, &org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3::toString, &x10::lang::Closure::typeName);
x10aux::itable_entry org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__3::_deserialize<x10::lang::Reference>,x10aux::CLOSURE_KIND_SIMPLE_ASYNC);

x10::lang::VoidFun_0_0::itable<org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4>org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4::_itable(&x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4::__apply, &org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4::toString, &x10::lang::Closure::typeName);
x10aux::itable_entry org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(org_scalegraph_io_impl_InputSplitter__SplitterContext__closure__4::_deserialize<x10::lang::Reference>,x10aux::CLOSURE_KIND_SIMPLE_ASYNC);

/* END of InputSplitter$SplitterContext */
/*************************************************/