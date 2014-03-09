#ifndef MYCLASS_H
#define MYCLASS_H

#include "OO/OO.h"
#include "Structure/Array.h"

RClass(MyClass)
{
    RInherit(RObject);
    int Prop1;
    int Prop2;
    Array_Define(int, MyArray);
};

int MyClass_Method(MyClass* This);

#endif

