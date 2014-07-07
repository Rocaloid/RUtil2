#define WITH_ASSERT_ABORT

#include "Structure/String_Utf8.h"
#include "Structure/UtfString.h"
#include "Misc/Convert.h"
#include "Core/OO.h"

void TestTor()
{
    String_Utf8 s;
    String_Utf8_Ctor(&s);
    String_Utf8_Dtor(&s);
}

void TestFromChars()
{
    String_Utf8_FromChars(s, "無限に広がる　夏の匂い");
    RAssert(! (strwcmp_utf8(s._Base.Data, "無限に広がる　夏の匂い", 11)));
    String_Utf8_Dtor(&s);
}

void TestSetChars()
{
    String_Utf8 s;
    String_Utf8_Ctor(&s);
    String_Utf8_SetChars(&s, "砂浜にあたしは　いつもいた");
    RAssert(! (strwcmp_utf8(s._Base.Data, "砂浜にあたしは　いつもいた", 13)));
    String_Utf8_Dtor(&s);
}

void TestSetCharsN()
{
    String_Utf8 s;
    String_Utf8_Ctor(&s);
    String_Utf8_SetCharsN(&s, "偶然見つけた　白い屋敷？", 11);
    RAssert(! (strwcmp_utf8(s._Base.Data, "また会え", 11)));
    String_Utf8_Dtor(&s);
}

void TestGetChars()
{
    String_Utf8_FromChars(s, "踏み入れた先は　白の世界");
    RAssert(! strcmp_utf8(String_Utf8_GetChars(&s), "踏み入れた先は　白の世界"));
    String_Utf8_Dtor(&s);
}

void TestCopy()
{
    String_Utf8 a, b;
    String_Utf8_Ctor(&a);
    String_Utf8_Ctor(&b);

    String_Utf8_SetChars(&a, "「僕に会いに来てくれたの？」");
    String_Utf8_SetChars(&b, "尋ねたのは白い君");
    String_Utf8_Copy(&a, &b);
    
    RAssert(a.WordNum == b.WordNum);
    RAssert(! strcmp_utf8(String_Utf8_GetChars(& a), 
                          String_Utf8_GetChars(& b)));
    
    String_Utf8_Dtor(&a);
    String_Utf8_Dtor(&b);
}

void TestGetWordNum()
{
    String_Utf8_FromChars(s, "色彩の薄い君は　笑顔が溶けそうだった");
    RAssert(String_Utf8_GetWordNum(&s) == 18);
    String_Utf8_Dtor(&s);
}

void TestAllocWordNum()
{
    String_Utf8_FromChars(s, "水平線に一人きり　孤独に包み込まれて");
    String_Utf8_AllocWordNum(&s, 0);
    String_Utf8_AllocWordNum(&s, 0xff);
    //String_Utf8_AllocWordNum(&s, -0xff); //should be String_Utf8_AllocWordNum(String_Utf8 *, size_t)
    String_Utf8_Dtor(&s);
}

void TestGetWord()
{
    String_Utf8 tmp;
    String_Utf8_Ctor(& tmp);
    String_Utf8_FromChars(s, "夏は熱を持ってるのに　冷めたままで");
    
    String_Utf8_GetWord(& s, & tmp, 2);
    RAssert(! (strwcmp_utf8("熱", tmp._Base.Data, 1)));
    
    String_Utf8_GetWord(& s, & tmp, 11);
    RAssert(! (strwcmp_utf8("冷", tmp._Base.Data, 1)));
    
    String_Utf8_Dtor(&s);
    String_Utf8_Dtor(& tmp);
}

void TestSetWord()
{
    String_Utf8_FromChars(s, "Uと出会えた夢たちが");
    String_Utf8_FromChars(w, "君");
    String_Utf8_SetWord(&s, 0, &w);
    
    RAssert(String_Utf8_GetWordNum(&s) == 10);
    RAssert(! strcmp_utf8(String_Utf8_GetChars(&s), "君と出会えた夢たちが"));
    
    String_Utf8_Dtor(&w);
    String_Utf8_Dtor(&s);
}


void TestJoin()
{
    String_Utf8_FromChars(a, "「僕も君");
    String_Utf8_FromChars(b, "を待ってたよ」");
    String_Utf8_Join(&a, &b);

    RAssert(String_Utf8_GetWordNum(&a) == 11);
    RAssert(! strcmp_utf8("「僕も君を待ってたよ」", String_Utf8_GetChars(&a)));
    
    String_Utf8_Dtor(&a);
    String_Utf8_Dtor(&b);
}

void TestJoinChars()
{
    String_Utf8_FromChars(s, "それからあたしは");
    String_Utf8_JoinChars(&s, " 呆れるくらい");

    RAssert(String_Utf8_GetWordNum(&s) == 15);
    RAssert(! strcmp_utf8("それからあたしは 呆れるくらい", 
                          String_Utf8_GetChars(&s)));
    
    String_Utf8_Dtor(&s);
}

void TestEqual()
{
    String_Utf8_FromChars(a, "毎日毎日　君の元へ");
    String_Utf8_FromChars(b, "君には外の話を　君はあたしに笑顔を");
    String_Utf8_FromChars(x, "毎日毎日　君の元へ");
    String_Utf8_FromChars(p, "毎日");
    
    RAssert(!String_Utf8_Equal(&a, &b));
    RAssert(String_Utf8_Equal(&a, &x));
    RAssert(String_Utf8_EqualN(&a, &p, 2));
    
    String_Utf8_Dtor(&a);
    String_Utf8_Dtor(&b);
    String_Utf8_Dtor(&x);
    String_Utf8_Dtor(&p);
}

void TestEqualChars()
{
    String_Utf8_FromChars(x, "外に出られない君は　世界に憧れてた");

    //should be bool String_Utf8_EqualChars(String_Utf8 *, const char *)
    RAssert(String_Utf8_EqualChars(&x, "外に出られない君は　世界に憧れてた"));
    RAssert(String_Utf8_EqualNChars(&x, "外に出られない君は", 9));
    
    String_Utf8_Dtor(&x);
}

void TestInStr()
{
    String_Utf8_FromChars(s, "白い屋敷に二人きり  君に包まれて");
    //                               ^           ^
    
    String_Utf8_FromChars(p, "に");
    RAssert(String_Utf8_InStr(& s, & p) == 4);
    RAssert(String_Utf8_InStrRev(& s, & p) == 12);
    String_Utf8_Dtor(& p);
    
    String_Utf8_Dtor(& s);
}

void TestMid()
{
    String_Utf8 d;
    String_Utf8_Ctor(& d);
    String_Utf8_FromChars(s, "こんな気持ちは一生に一度　それだけなの");
    
    Mid_Utf8(&d, &s, 7, 5);
    RAssert(String_Utf8_EqualChars(&d, "一生に一度"));
    
    MidFrom_Utf8(&d, &s, 13);
    RAssert(String_Utf8_EqualChars(&d, "それだけなの"));
    
    Mid_Utf8(&d, &s, 0, 7);
    RAssert(String_Utf8_EqualChars(&d, "こんな気持ちは"));
    
    Mid_Utf8(&d, &s, 0, 0);
    RAssert(String_Utf8_EqualChars(&d, ""));
    
    Mid_Utf8(&d, &s, 19, 0);
    RAssert(String_Utf8_EqualChars(&d, ""));
    
    String_Utf8_Dtor(& s);
    String_Utf8_Dtor(& d);
}

void TestLR()
{
    String_Utf8_FromChars(s, "君と出会えた奇跡が　私に笑顔をくれる");
    String_Utf8 d;
    String_Utf8_Ctor(& d);
    
    Left_Utf8(&d, &s, 9);
    RAssert(String_Utf8_EqualChars(&d, "君と出会えた奇跡が"));
    
    Right_Utf8(&d, &s, 8);
    RAssert(String_Utf8_EqualChars(&d, "私に笑顔をくれる"));
    
    Left_Utf8(&d, &s, 0);
    RAssert(String_Utf8_EqualChars(&d, ""));
    
    Right_Utf8(&d, &s, 0);
    RAssert(String_Utf8_EqualChars(&d, ""));
    
    String_Utf8_Dtor(& s);
    String_Utf8_Dtor(& d);
}

void TestTrim()
{
    String_Utf8_FromChars(a, "    強く握った君の手が　いなくなった    ");
    String_Utf8_FromChars(b, "    N   ");
    String_Utf8_FromChars(c, "    桜   ");
    String_Utf8 d;
    String_Utf8_Ctor(& d);
    
    Trim_Utf8(& d, & a);
    RAssert(String_Utf8_EqualChars(&d, "強く握った君の手が　いなくなった"));
    
    Trim_Utf8(& d, & b);
    RAssert(String_Utf8_EqualChars(&d, "N"));
    
    Trim_Utf8(& d, & c);
    RAssert(String_Utf8_EqualChars(&d, "桜"));
    
    LTrim_Utf8(& d, & a);
    RAssert(String_Utf8_EqualChars(&d, "強く握った君の手が　いなくなった    "));
    
    LTrim_Utf8(& d, & b);
    RAssert(String_Utf8_EqualChars(&d, "N   "));
    
    LTrim_Utf8(& d, & c);
    RAssert(String_Utf8_EqualChars(&d, "桜   "));
    
    RTrim_Utf8(& d, & a);
    RAssert(String_Utf8_EqualChars(&d, "    強く握った君の手が　いなくなった"));
    
    RTrim_Utf8(& d, & b);
    RAssert(String_Utf8_EqualChars(&d, "    N"));
    
    RTrim_Utf8(& d, & c);
    RAssert(String_Utf8_EqualChars(&d, "    桜"));
    
    String_Utf8_Dtor(& d);
    String_Utf8_Dtor(& b);
    String_Utf8_Dtor(& a);
}

int main()
{
    TestTor(); // Will great water wall block it? LOL
    TestFromChars();
    TestSetChars();
    TestGetChars();
    TestCopy();
    TestGetWordNum();
    TestAllocWordNum();
    TestGetWord();
    TestSetWord();
    TestJoin();
    TestJoinChars();
    TestEqual();
    TestEqualChars();
    TestInStr();
    TestMid();
    TestLR();
    TestTrim();
    
    return 0;
}

#undef WITH_ASSERT_ABORT
