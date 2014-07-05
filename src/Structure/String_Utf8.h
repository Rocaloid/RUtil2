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

//Member Functions
void String_Utf8_SetChars(String_Utf8* This, char* Chars);
void String_Utf8_SetCharsN(String_Utf8* This, char* Chars, int Length);
char* String_Utf8_GetChars(String_Utf8* This);

void String_Utf8_Copy(String_Utf8* This, String_Utf8* Sorc);

int String_Utf8_GetLength(String_Utf8* This);
void String_Utf8_AllocLength(String_Utf8* This, int Length);

char String_Utf8_GetChar(String_Utf8* This, int Index);
void String_Utf8_SetChar(String_Utf8* This, int Index, char Data);

void String_Utf8_Join(String_Utf8* This, String_Utf8* Sorc);
void String_Utf8_JoinChars(String_Utf8* This, char* Sorc);

int String_Utf8_Equal(String_Utf8* This, String_Utf8* Sorc);
int String_Utf8_EqualN(String_Utf8* This, String_Utf8* Sorc, int n);
int String_Utf8_EqualChars(String_Utf8* This, char* Sorc);
int String_Utf8_EqualNChars(String_Utf8* This, char* Sorc, int n);

int String_Utf8_InStrFrom(String_Utf8* This, String_Utf8* Sorc, int From);
int String_Utf8_InStr(String_Utf8* This, String_Utf8* Sorc);
int String_Utf8_InStrRevFrom(String_Utf8* This, String_Utf8* Sorc, int From);
int String_Utf8_InStrRev(String_Utf8* This, String_Utf8* Sorc);

//Abbreviations
#define InStrFrom_Utf8    String_Utf8_InStrFrom
#define InStr_Utf8        String_Utf8_InStr
#define InStrRevFrom_Utf8 String_Utf8_InStrRefFrom
#define InStrRev_Utf8     String_Utf8_InStrRev

//String Utils
void Mid_Utf8(String* Dest, String* Sorc, int From, int Count);
void MidFrom_Utf8(String* Dest, String* Sorc, int From);
void Right_Utf8(String* Dest, String* Sorc, int Count);
void Left_Utf8(String* Dest, String* Sorc, int Count);

void UpperCase_Utf8(String* Dest, String* Sorc);
void LowerCase_Utf8(String* Dest, String* Sorc);

void Trim_Utf8(String* Dest, String* Sorc);
void LTrim_Utf8(String* Dest, String* Sorc);
void RTrim_Utf8(String* Dest, String* Sorc);

#endif //RUTIL2_STRING_UTF8_H

