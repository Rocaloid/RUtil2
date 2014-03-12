#include <assert.h>
#include "Structure/String.h"
#include "Misc/Convert.h"

void TestTor()
{
    String s;
    String_Ctor(&s);
    String_Dtor(&s);
}

void TestFromChars()
{
    String_FromChars(s, "Rocaloid");
    String_Dtor(&s);
}

void TestSetChars()
{
    String s;
    String_Ctor(&s);
    String_SetChars(&s, "Rocaloid");
    String_Dtor(&s);
}

void TestGetChars()
{
    String_FromChars(s, "Rocaloid");
    String_GetChars(&s);
    String_Dtor(&s);
}

void TestCopy()
{
    String a, b;
    String_Ctor(&a);
    String_Ctor(&b);

    String_SetChars(&a, "Rocaloid");
    String_SetChars(&b, "Vocaloid");
    String_Copy(&a, &b);

    String_Dtor(&a);
    String_Dtor(&b);
}

void TestGetLength()
{
    String_FromChars(s, "Rocaloid");
    assert(String_GetLength(&s) == 8);
    String_Dtor(&s);
}

void TestAllocLength()
{
    String_FromChars(s, "Rocaloid");
    String_AllocLength(&s, 0);
    String_AllocLength(&s, 0xff);
    //String_AllocLength(&s, -0xff); //should be String_AllocLength(String *, size_t)
    String_Dtor(&s);
}

void TestGetChar()
{
    String_FromChars(s, "Rocaloid");
    assert(String_GetChar(&s, 0) == 'R');
    String_Dtor(&s);
}

void TestSetChar()
{
    String_FromChars(s, "Vocaloid");
    String_SetChar(&s, 0, 'R');
    assert(String_GetChar(&s, 0) == 'R');
    String_Dtor(&s);
}

void TestJoin()
{
    String_FromChars(a, "Roca");
    String_FromChars(b, "loid");
    String_Join(&a, &b);

    assert(String_GetLength(&a) == 8);

    String_Dtor(&a);
    String_Dtor(&b);
}

void TestJoinChars()
{
    String_FromChars(s, "Roca");
    String_JoinChars(&s, "loid");

    assert(String_GetLength(&s) == 8);

    String_Dtor(&s);
}

void TestEqual()
{
    String_FromChars(a, "Rocaloid");
    String_FromChars(b, "Vocaloid");
    String_FromChars(x, "Rocaloid");

    //String_Equal should return bool?
    assert(!String_Equal(&a, &b));
    assert(String_Equal(&a, &x));

    String_Dtor(&a);
    String_Dtor(&b);
    String_Dtor(&x);
}

void TestEqualChars()
{
    String_FromChars(x, "Rocaloid");

    //should be bool String_EqualChars(String *, const char *)
    assert(String_EqualChars(&x, "Rocaloid"));

    String_Dtor(&x);
}


int main()
{
    TestTor();
    TestFromChars();
    TestSetChars();
    TestGetChars();
    TestCopy();
    TestGetLength();
    TestAllocLength();
    TestGetChar();
    TestSetChar();
    TestJoin();
    TestJoinChars();
    TestEqual();
    TestEqualChars();
    
    return 0;
}

