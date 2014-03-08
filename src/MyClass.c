#include "MyClass.h"
#include <stdio.h>

RCtor(MyClass)
{
    This -> Prop1 = 0;
    This -> Prop2 = 0;
    RInit(MyClass);
    printf("MyClass: %d\n", MyBase(RObject) -> ClassID);
}

RDtor(MyClass)
{
    printf("MyClass Dtor\n");
}

int MyClass_Method(MyClass* This)
{
    return This -> Prop1 + This -> Prop2;
}

