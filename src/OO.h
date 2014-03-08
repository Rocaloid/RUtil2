/*
    Title: OO

        Object Oriented Programming in C.
*/

#ifndef OO_H
#define OO_H

/*
    Section: Globals

    Variable: __ClassID__

        The counter which assigns each RClass a unique class number.
        
        Automatically increases by 1 when a RClass is defined.
*/
int __ClassID__;

/*
    Macro: RClass

        Defines a RClass.
        
        Usage:
        
        (start code)
        RClass(ClassName)
        {
            ...
        };
        (end)
        
        Example:
        
        (start code)
        RClass(MyClass)
        {
            RInherit(RObject);
            int a;
            int b;
            int c;
        };
        (end)
        
    See also:
    
        <RInherit>
        
        <RCtor>
        
        <RDtor>
        
        <RInit>
*/
#define RClass(Name) \
    typedef struct Name Name; \
    int __ClassID_##Name##__; \
    void Name##_Ctor(Name* This); \
    void Name##_Dtor(Name* This); \
    struct Name

/*
    Macro: RInherit

        Inherit a RClass from another RClass.
        
        All RClasses should at least inherit RObject.
        
        Usage:
        
        (start code)
        RClass(ClassName)
        {
            RInherit(BaseClassName);
            ...
        };
        (end)
        
        Example:
        
        (start code)
        RClass(MyBaseClass)
        {
            RInherit(RObject);
            int a;
            int b;
            int c;
        };
        
        RClass(MyParentClass)
        {
            RInherit(MyBaseClass);
            int d;
            int e;
            int f;
        };
        (end)
        
    See also:
    
        <RClass>
*/
#define RInherit(BaseClass) \
    BaseClass _Base

/*
    Macro: RCtor

        Defines the constructor of a RClass.
        
        All RClasses should have a constructor.
        
        Usage:
        
        > RCtor(a)
        
        This is equivalent to
        
        > void a_Ctor(a* This)
        
        Example:
        
        (start code)
        RClass(MyClass)
        {
            RInherit(RObject);
            int a;
            int b;
            int c;
        };
        
        RCtor(MyClass)
        {
            This -> a = 0;
            This -> b = 0;
            This -> c = 0;
            RInit(MyClass);
        };
        (end)
        
    See also:
    
        <RClass>
        
        <RInit>
        
        <RDtor>
*/
#define RCtor(Name) \
    void __attribute__ ((constructor)) __##Name##_ClassInit__() \
    { \
        __ClassID_##Name##__ = __ClassID__ ++; \
    }\
    void Name##_Ctor(Name* This)

/*
    Macro: RDtor

        Defines the destructor of a RClass.
        
        All RClasses should have a destructor.
        
        Usage:
        
        > RDtor(a)
        
        This is equivalent to
        
        > void a_Dtor(a* This)
        
        Example:
        
        (start code)
        RClass(MyBaseClass)
        {
            RInherit(RObject);
            int a;
            int b;
            int c;
        };
        
        RDtor(MyClass)
        {
            This -> a = 0;
            This -> b = 0;
            This -> c = 0;
        };
        (end)
        
    See also:
    
        <RClass>
        
        <RCtor>
*/
#define RDtor(Name) \
    void Name##_Dtor(Name* This)

/*
    Macro: RInit

        Assigns the ClassID to the object.
        
        Should be placed in the end of every RCtors.
        
        Usage:
        
        > RInit(ClassName);
        
        Example:
        
        (start code)
        RClass(MyClass)
        {
            RInherit(RObject);
            int a;
            int b;
            int c;
        };
        
        RCtor(MyClass)
        {
            This -> a = 0;
            This -> b = 0;
            This -> c = 0;
            RInit(MyClass);
        };
        (end)
*/
#define RInit(Name) \
    ((RObject*)This) -> ClassID = __ClassID_##Name##__;

/*
    Macro: MyBase

        Converts 'This' pointer to a specified base class.
        
        Usage:
        
        > MyBase(BaseClassName);
        
        Example:
        
        (start code)
        RClass(MyClass)
        {
            RInherit(RObject);
        };
        
        RCtor(MyClass)
        {
            printf("My ClassID is %d\n", MyBase(RObject) -> ClassID);
            RInit(MyClass);
        };
        (end)
        
        See also:
        
            <RInherit>
*/
#define MyBase(Name) \
    ((Name*)This)

/*
    Macro: RInterface_Start

        Marks the start of RInterface definition.
        
        Usage:
        
        > RInterface_Start();
        
    See also:
    
        <RInterface_Add>
*/
#define RInterface_Start() \
    if(0) \
        __ClassID__ = __ClassID__

/*
    Macro: RInterface_Add

        Add a method to a RInterface method.
        
        Usage:
            
        > RInterface_Add(ClassName, MethodName)(Arg1, Arg2, ...);
        
        Example:
        
        (start code)
        int MyClass_Method(MyClass* This)
        {
            ...
        }
        
        int MyClass2_Method(MyClass2* This)
        {
            ...
        }

        int IObject_Method(RObject* This)
        {
            RInterface_Start();
            RInterface_Add(MyClass, Method)(MyBase(MyClass));
            RInterface_Add(MyClass2, Method)(MyBase(MyClass2));
            return 0;
        }
        (end)
        
    See also:
    
        <RInterface_Start>
*/
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

