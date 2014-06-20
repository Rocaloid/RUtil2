#include <stdio.h>
#include <string.h>
#include "Core/RAlloc.h"
#include "Structure/String.h"
#include "Misc/Base64.h"

int TestNr = 0;

static char TestCStr1[] = "Hello World!";                      //12 % 4 == 0.
static char TestCStr2[] = "What a fucky day today! Isn't it?"; //33 % 4 == 1.
static char TestCStr3[] = "How do u think it?";                //18 % 4 == 2.
static char TestCStr4[] = "I think you also will think so.";   //31 % 4 == 3.
static char TestCStr5[] = "";

static int TestBase64_Str_Func(char *CStr)
{
    int Ret = 0;
    printf("Base64 Test, Nr = %d: \n", ++ TestNr);
    
    String o;
    String p;
    String_Ctor(& o);
    String_Ctor(& p);
    
    int RawSize = (int)strlen(CStr);
    
    printf("    Raw string: '%s', Size = %d.\n", CStr, RawSize);
    
    int EncSize = Base64_Encode(& o, (void*)CStr, RawSize);
    printf("    Base64 encoded: String = '%s', Size = %d, RetS = %d\n",
        String_GetChars(& o), String_GetLength(& o), EncSize);
    
    int OSize = Base64_DecodeSize(String_GetLength(& o));
    String_AllocLength(& p, OSize);
    p.Data_Index = Base64_Decode((void*)p.Data, & o) - 1;
    printf("    Base64 decoded: String = '%s', Size = %d, "
        "RetS = %d, RetEst = %d.\n",
        String_GetChars(& p), String_GetLength(& p), p.Data_Index + 1, OSize);
    
    if((Ret = (String_GetLength(& p) != RawSize)))
        printf("[Error] Test isn't passed! Nr = %d!\n", TestNr);

    String_Dtor(& p);
    String_Dtor(& o);
    return Ret;
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

