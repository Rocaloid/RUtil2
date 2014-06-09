#ifndef RUTIL2_STRING_H
#define RUTIL2_STRING_H

#include "../Core/OO.h"
#include "Array.h"

RClass(String)
{
    RInherit(RObject);
    Array_Define(char, Data);
};

#define String_FromChars(name, chars) \
    String name; \
    do \
    { \
        String_Ctor(& name); \
        String_SetChars(& name, chars); \
    } while(0)

//Member Functions
void String_SetChars(String* This, char* Chars);
void String_SetCharsN(String* This, char* Chars, int Length);
char* String_GetChars(String* This);

void String_Copy(String* This, String* Sorc);

int String_GetLength(String* This);
void String_AllocLength(String* This, int Length);

char String_GetChar(String* This, int Index);
void String_SetChar(String* This, int Index, char Data);

void String_Join(String* This, String* Sorc);
void String_JoinChars(String* This, char* Sorc);

int String_Equal(String* This, String* Sorc);
int String_EqualChars(String* This, char* Sorc);

int String_InStrFrom(String* This, String* Sorc, int From);
int String_InStr(String* This, String* Sorc);
int String_InStrRevFrom(String* This, String* Sorc, int From);
int String_InStrRev(String* This, String* Sorc);

//Abbreviations
#define InStrFrom    String_InStrFrom
#define InStr        String_InStr
#define InStrRevFrom String_InStrRefFrom
#define InStrRev     String_InStrRev

//String Utils
void Mid(String* Dest, String* Sorc, int From, int Count);
void MidFrom(String* Dest, String* Sorc, int From);
void Right(String* Dest, String* Sorc, int Count);
void Left(String* Dest, String* Sorc, int Count);

void UpperCase(String* Dest, String* Sorc);
void LowerCase(String* Dest, String* Sorc);

void Trim(String* Dest, String* Sorc);
void LTrim(String* Dest, String* Sorc);
void RTrim(String* Dest, String* Sorc);

#endif //RUTIL2_STRING_H

