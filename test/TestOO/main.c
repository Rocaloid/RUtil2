#include <stdio.h>
#include "Core/OO.h"
#include "Structure/PMatch.h"
#include "MyClass.h"
#include "MyPrint.h"

RClass(MyInherit)
{
    RInherit(MyClass);
    int Prop3;
};

RCtor(MyInherit)
{
    MyClass_Ctor(MyBase(MyClass));
    RInit(MyInherit);
    printf("MyInherit: %d\n", MyBase(RObject) -> ClassID);
}

RDtor(MyInherit)
{
    printf("MyInherit Dtor\n");
    MyClass_Dtor(MyBase(MyClass));
}

int MyInherit_Method(MyInherit* This)
{
    Array_Push(int, MyBase(MyClass) -> MyArray, 
        MyBase(MyClass) -> Prop1 + 
        MyBase(MyClass) -> Prop2 + This -> Prop3);
    return TopOf(MyBase(MyClass) -> MyArray);
}

int IObject_Method(RObject* This)
{
    RInterface_Start();
    RInterface_Add(MyClass, Method)(MyBase(MyClass));
    RInterface_Add(MyInherit, Method)(MyBase(MyInherit));
    return 0;
}

int main(void)
{
    MyClass a;
    MyInherit b;
    MyClass_Ctor(& a);
    MyInherit_Ctor(& b);
    a.Prop1 = 5;
    a.Prop2 = 3;
    b._Base.Prop1 = 8;
    b._Base.Prop2 = 10;
    b.Prop3 = 15;
    
    printf("MyClass_Method: %d\n", MyClass_Method((MyClass*)(& b)));
    printf("MyInherit_Method: %d\n", MyInherit_Method(& b));
    printf("IObject_Method of MyClass: %d\n", IObject_Method((RObject*)(& a)));
    printf("IObject_Method of MyInherit: %d\n", 
        IObject_Method((RObject*)(& b)));
    
    #undef _ClassName
    #define _ClassName PMatch_double_double
    _ClassName c;
    RCall(_ClassName, Ctor)(& c);
    RCall(_ClassName, AddPair)(& c, 0, 1.5452334545);
    RCall(_ClassName, AddPair)(& c, 1, 2.53245345);
    RCall(_ClassName, AddPair)(& c, 5, 0);
    RCall(_ClassName, AddPair)(& c, 6, 0.3454353545);
    RCall(_ClassName, Print)(& c);
    int i;
    for(i = 0; i < 60; i ++)
    {
        printf("%d, %.9lf\n", i, 
            RCall(_ClassName, Query)(& c, (double)i / 10.0).Y);
    }
    RCall(_ClassName, Dtor)(& c);
    
    MyPrint_float(213.234353423);
    MyPrint_double(213.234353423);
    
    MyClass_Dtor(& a);
    MyInherit_Dtor(& b);
    return 0;
}

