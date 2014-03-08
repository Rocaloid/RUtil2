#include <stdio.h>
#include "OO.h"
#include "MyClass.h"

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
    MyClass_Dtor(MyBase(MyClass));
    printf("MyInherit Dtor\n");
}

int MyInherit_Method(MyInherit* This)
{
    return MyBase(MyClass) -> Prop1 + 
           MyBase(MyClass) -> Prop2 + This -> Prop3;
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
    printf("IObject_Method of MyInherit: %d\n", IObject_Method((RObject*)(& b)));
    
    MyClass_Dtor(& a);
    MyInherit_Dtor(& b);
    return 0;
}

