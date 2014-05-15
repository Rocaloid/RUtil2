RUtil2
======

Rocaloid Coding Utility 2

* Language: C99

* License: MIT License

Tutorial
===

####Hello World

    #include <RUtil2.h>
    int main()
    {
        String Hello;
        String_Ctor(& Hello);
        String_SetChars(& Hello, "Hello, world!\n");
        printf("%s", String_GetChars(& Hello));
        String_Dtor(& Hello);
        return 0;
    }

Compile:

    gcc hello.c -lRUtil2

####Join some Strings

    #include <RUtil2.h>
    int main()
    {
        String Str1, Str2;
        String_Ctor(& Str1);
        String_Ctor(& Str2);
    
        String_SetChars(& Str1, "Hello");
        String_SetChars(& Str2, "World");
        String_JoinChars(& Str1, ", ");
        String_Join(& Str1, & Str2);
        String_JoinChars(& Str1, "!\n");
        printf("%s", String_GetChars(& Str1));
    
        String_Dtor(& Str1);
        String_Dtor(& Str2);
        return 0;
    }

####Batch Constructor and Destructor

    #include <RUtil2.h>
    int main()
    {
        String Str1, Str2;
        RNew(String, & Str1, & Str2);

        String_SetChars(& Str1, "Hello");
        String_SetChars(& Str2, "World");
        String_JoinChars(& Str1, ", ");
        String_Join(& Str1, & Str2);
        String_JoinChars(& Str1, "!\n");
        printf("%s", String_GetChars(& Str1));
    
        RDelete(& Str1, & Str2);
        return 0;
    }

####Define a Class

<pre>
RClass(MyClass)
{
    //This must be placed on the top.
    //And make sure every class inherits RObject directly or indirectly.
    RInherit(RObject);

    int MyVal;
    String MyString;
};
</pre>

####Define the Constructor and Destructor

<pre>
RCtor(MyClass)
{
    String_Ctor(& This -> MyString);
    //Important!
    //This assigns a ClassID to the newly created instance of MyClass.
    //Each class in RUtil has a unique ClassID;
    //Each instance of the same class share the same ClassID.
    RInit(MyClass);
}

RDtor(MyClass)
{
    String_Dtor(& This -> MyString);
}
</pre>

####Define some Methods!

<pre>
void MyClass_Set(MyClass* This, int SorcNum, String* SorcStr)
{
    This -> MyVal = SorcNum;
    String_Copy(& This -> MyString, SorcStr);
}

void MyClass_Print(MyClass* This)
{
    printf("MyVal is: %d\n", This -> MyVal);
    printf("MyString is : %s\n", String_GetChars(& This -> MyString));
}
</pre>

####The Complete Code & Use our Class

MyClass.h:

    #include <RUtil2.h>
    
    RClass(MyClass)
    {
        //This must be placed on the top.
        //And make sure every class inherits RObject directly or indirectly.
        RInherit(RObject);
    
        int MyVal;
        String MyString;
    };

MyClass.c:

<pre>
#include "MyClass.h"

RCtor(MyClass)
{
    String_Ctor(& This -> MyString);
    //Important!
    //This assigns a ClassID to the newly created instance of MyClass.
    //Each class in RUtil has a unique ClassID;
    //Each instance of the same class share the same ClassID.
    RInit(MyClass);
}

RDtor(MyClass)
{
    String_Dtor(& This -> MyString);
}

void MyClass_Set(MyClass* This, int SorcNum, String* SorcStr)
{
    This -> MyVal = SorcNum;
    String_Copy(& This -> MyString, SorcStr);
}

void MyClass_Print(MyClass* This)
{
    printf("MyVal is: %d\n", This -> MyVal);
    printf("MyString is : %s\n", String_GetChars(& This -> MyString));
}
</pre>

main.c:

<pre>
#include "MyClass.h"

int main()
{
    MyClass MyInstance;
    MyClass_Ctor(& MyInstance);

    String Str;
    String_Ctor(& Str);
    String_SetChars(& Str, "abcdef");

    MyClass_Set(& MyInstance, 100, & Str);
    MyClass_Print(& MyInstance);

    RDelete(& MyInstance, & Str);
    return 0;
}
</pre>

Compile:

    gcc MyClass.c main.c -lRUtil2
