#ifndef OO_H
#define OO_H

#include "MacroUtil.h"

int __ClassID__;

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
        _C2(__ClassID_, Name, __) = __ClassID__ ++; \
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

