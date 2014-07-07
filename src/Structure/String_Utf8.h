#ifndef RUTIL2_STRING_UTF8_H
#define RUTIL2_STRING_UTF8_H

#include "String.h"
#include "../Core/OO.h"

RClass(String_Utf8)
{
    RInherit(String);
    int WordNum;
};

#define String_Utf8_FromChars(name, chars) \
    String_Utf8 name; \
    do \
    { \
        String_Utf8_Ctor(& name); \
        String_Utf8_SetChars(& name, chars); \
    } while(0)

RINLINE char* String_Utf8_GetChars(String_Utf8* This)
{
    return String_GetChars(& (This -> _Base));
}

RINLINE void String_Utf8_AllocLength(String_Utf8* This, int Length)
{
    String_AllocLength(& (This -> _Base), Length);
}

RINLINE int String_Utf8_GetLength(String_Utf8* This)
{
    return String_GetLength(& (This -> _Base));
}

RINLINE int String_Utf8_Equal(String_Utf8* This, String_Utf8* Sorc)
{
    return String_Equal(& (This -> _Base), & (Sorc -> _Base));
}

RINLINE int String_Utf8_EqualChars(String_Utf8* This, char* Sorc)
{
     return String_EqualChars(& (This -> _Base), Sorc);
}

//Member Functions

void String_Utf8_AllocWordNum(String_Utf8* This, int WordNum);

void String_Utf8_SetChars(String_Utf8* This, const char* Chars);
void String_Utf8_SetCharsN(String_Utf8* This, const char* Chars, int WordNum);

void String_Utf8_Copy(String_Utf8* This, String_Utf8* Sorc);

int String_Utf8_GetWordNum(String_Utf8* This);

void String_Utf8_GetWord(String_Utf8* This, String_Utf8* Dest, int Index);
void String_Utf8_SetWord(String_Utf8* This, int Index, String_Utf8* Data);

void String_Utf8_Join(String_Utf8* This, String_Utf8* Sorc);
void String_Utf8_JoinChars(String_Utf8* This, char* Sorc);

int String_Utf8_Equal(String_Utf8* This, String_Utf8* Sorc);
int String_Utf8_EqualN(String_Utf8* This, String_Utf8* Sorc, int w);
int String_Utf8_EqualChars(String_Utf8* This, char* Sorc);
int String_Utf8_EqualNChars(String_Utf8* This, char* Sorc, int w);

int String_Utf8_InStrFrom(String_Utf8* This, String_Utf8* Part, int From);
int String_Utf8_InStr(String_Utf8* This, String_Utf8* Part);
int String_Utf8_InStrRevFrom(String_Utf8* This, String_Utf8* Part, int From);
int String_Utf8_InStrRev(String_Utf8* This, String_Utf8* Part);

//Abbreviations
#define InStrFrom_Utf8    String_Utf8_InStrFrom
#define InStr_Utf8        String_Utf8_InStr
#define InStrRevFrom_Utf8 String_Utf8_InStrRefFrom
#define InStrRev_Utf8     String_Utf8_InStrRev

//String_Utf8 Utils
void Mid_Utf8(String_Utf8* Dest, String_Utf8* Sorc, int From, int Count);
void MidFrom_Utf8(String_Utf8* Dest, String_Utf8* Sorc, int From);
void Right_Utf8(String_Utf8* Dest, String_Utf8* Sorc, int Count);
void Left_Utf8(String_Utf8* Dest, String_Utf8* Sorc, int Count);

void UpperCase_Utf8(String_Utf8* Dest, String_Utf8* Sorc);
void LowerCase_Utf8(String_Utf8* Dest, String_Utf8* Sorc);

void Trim_Utf8(String_Utf8* Dest, String_Utf8* Sorc);
void LTrim_Utf8(String_Utf8* Dest, String_Utf8* Sorc);
void RTrim_Utf8(String_Utf8* Dest, String_Utf8* Sorc);

#endif //RUTIL2_STRING_UTF8_H

