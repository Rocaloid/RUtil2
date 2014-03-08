#ifndef MYCLASS_H
#define MYCLASS_H

#include "OO.h"

RClass(MyClass)
{
    RInherit(RObject);
    int Prop1;
    int Prop2;
};

int MyClass_Method(MyClass* This);

#endif

