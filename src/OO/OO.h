#ifndef OO_H
#define OO_H

int __ClassID__;

#define RClass(Name) \
    typedef struct Name Name; \
    int __ClassID_##Name##__; \
    void Name##_Ctor(Name* This); \
    void Name##_Dtor(Name* This); \
    struct Name

#define RInherit(BaseClass) \
    BaseClass _Base

#define RCtor(Name) \
    void __attribute__ ((constructor)) __##Name##_ClassInit__() \
    { \
        __ClassID_##Name##__ = __ClassID__ ++; \
    }\
    void Name##_Ctor(Name* This)

#define RDtor(Name) \
    void Name##_Dtor(Name* This)

#define RInit(Name) \
    ((RObject*)This) -> ClassID = __ClassID_##Name##__;

#define MyBase(Name) \
    ((Name*)This)

#define RInterface_Start() \
    if(0) \
        __ClassID__ = __ClassID__

#define RInterface_Add(Class, Method) \
    else if(This -> ClassID == __ClassID_##Class##__) \
        return Class##_##Method

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

