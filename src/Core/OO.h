#ifndef OO_H
#define OO_H

#include "MacroUtil.h"
#include "../Structure/Array.h"
#include <stdint.h>

int __ClassID__;

//Rocaloid-style type aliases.
typedef float               Float;
typedef double              Double;
typedef int                 Int;
typedef unsigned int        UInt;
typedef short int           Short;
typedef unsigned short int  UShort;
typedef char                Char;
typedef unsigned char       UChar;
typedef int16_t             Int16;
typedef uint16_t            UInt16;
typedef int32_t             Int32;
typedef uint32_t            UInt32;
typedef int64_t             Int64;
typedef uint64_t            UInt64;

//Automatic constructor/destructor.
typedef void (*__CDtorFunc)(void*);
Array_Define(__CDtorFunc, __AutoCtor);
Array_Define(__CDtorFunc, __AutoDtor);
void __AutoCDtor_Init();
void __RNew(__CDtorFunc Ctor, ...);
void __RDelete(void* a, ...);
#define RNew(Type, ...) \
    __RNew(__AutoCtor[_C2(__ClassID_, Type, __)], __VA_ARGS__, (void*)(- 1));
#define RDelete(...) __RDelete(__VA_ARGS__, (void*)(- 1));

#define RClass(Name) \
    typedef struct Name Name; \
    int _C2(__ClassID_, Name, __); \
    void _C1(Name, _Ctor)(Name* This); \
    void _C1(Name, _Dtor)(Name* This); \
    struct Name

#define RInherit(BaseClass) \
    BaseClass _Base

#define RCtor(Name) \
    void __attribute__ ((constructor)) _C2(__, Name, _ClassInit__)() \
    { \
        if(__ClassID__ == 0) \
            __AutoCDtor_Init(); \
        _C2(__ClassID_, Name, __) = __ClassID__ ++; \
        Array_Push(__CDtorFunc, __AutoCtor, (__CDtorFunc)_C1(Name, _Ctor)); \
        Array_Push(__CDtorFunc, __AutoDtor, (__CDtorFunc)_C1(Name, _Dtor)); \
    }\
    void _C1(Name, _Ctor)(Name* This)

#define RDtor(Name) \
    void _C1(Name, _Dtor)(Name* This)

#define RInit(Name) \
    ((RObject*)This) -> ClassID = _C2(__ClassID_, Name, __);

#define MyBase(Name) \
    ((Name*)This)

#define RInterface_Start() \
    if(0) \
        __ClassID__ = __ClassID__

#define RInterface_Add(Class, Method) \
    else if(This -> ClassID == _C2(__ClassID_, Class, __)) \
        return _C2(Class, _, Method)

#define RTMethod(Ret, Name, Method, ...) \
    Ret _C(_RTClassName, _, Method) \
        (_RTClassName* This, ##__VA_ARGS__)

#define RTFunc(Ret, Method, ...) \
    Ret _C(Method, _, __Attr) \
        (__VA_ARGS__)

#define RTAttr_1 _, _T1
#define RTAttr_2 _, _T1, _, _T2
#define RTAttr_3 _, _T1, _, _T2, _, _T3
#define RTAttr_4 _, _T1, _, _T2, _, _T3, _, _T4

#define RCall(Class, Method) _C2(Class, _, Method)

/*
    Class: RObject
    
        The base class of all RClasses.
*/
RClass(RObject)
{
    /*
        Variable: ClassID
        
            Stores the unique ID representing the RClass of this object.
    */
    int ClassID;
};

#endif

#undef _RTAddress
#undef _ClassName
#undef _Attr

