#include <stdio.h>
#include <string.h>
#include "Core/RAlloc.h"
#include "Structure/String.h"
#include "Misc/Base64.h"

int TestNr = 0;

static const char TestCStr1[] = "Hello World!";                      //12 % 4 == 0.
static const char TestCStr2[] = "What a fucky day today! Isn't it?"; //33 % 4 == 1.
static const char TestCStr3[] = "How do u think it?";                //18 % 4 == 2.
static const char TestCStr4[] = "I think you also will think so.";   //31 % 4 == 3.
static const char TestCStr5[] = "";

static int TestBase64_Str_Func(const char *CStr)
{
    int retval = 0;
    printf("Base64 Test, Nr=%d: \n", ++TestNr);
    
    String o;
    String p;
    String_Ctor(& o);
    String_Ctor(& p);
    
    int RawLen = (int)strlen(CStr);
    
    printf("    Raw string: '%s', Length=%d.\n", CStr, RawLen);
    
    Base64_Encode(& o, (void *)CStr, RawLen);
    printf("    Base64 encoded: String='%s', Length=%d.\n", String_GetChars(& o), String_GetLength(& o));
    
    int OLen = Base64_DecodeSize(String_GetLength(& o));
    String_AllocLength(& p, OLen);
    p.Data_Index=Base64_Decode((void *)p.Data, & o) - 1;
    printf("    Base64 decoded: String='%s', Length=%d.\n", String_GetChars(& p), String_GetLength(& p));
    
    if((retval=(String_GetLength(& p) != RawLen))) printf("[Error] Test isn't passed! Nr=%d!\n", TestNr);
    
    String_Dtor(& p);
    String_Dtor(& o);
    return retval;
}

int main()
{
    if(TestBase64_Str_Func(TestCStr1)) return 1;
    if(TestBase64_Str_Func(TestCStr2)) return 1;
    if(TestBase64_Str_Func(TestCStr3)) return 1;
    if(TestBase64_Str_Func(TestCStr4)) return 1;
    if(TestBase64_Str_Func(TestCStr5)) return 1;
    printf("\n");
    return 0;
}

