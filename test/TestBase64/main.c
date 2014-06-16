#include <stdio.h>
#include <string.h>
#include "Core/RAlloc.h"
#include "Structure/String.h"
#include "Misc/Base64.h"

static const char str[] = "What a fucky day! Isn't it?";

int main()
{
    String o;
    String p;
    String_Ctor(& o);
    String_Ctor(& p);
    printf("Raw string: '%s', Length=%d.\n", str, (int)strlen(str));
    int RL1 = Base64_Encode(& o, (void *)str, sizeof(str));
    printf("Base64 encoded: String='%s', Length=%d, RetLen=%d.\n", String_GetChars(& o), (int)strlen(String_GetChars(& o)), RL1);
    
    int OLen = Base64_DecodeSize(String_GetLength(& o));
    String_AllocLength(& p, OLen);
    int RL2=Base64_Decode((void *)p.Data, & o);
    p.Data_Index=RL2-1;
    printf("Base64 decoded: String='%s', Length=%d, RetLen=%d.\n", String_GetChars(& p), String_GetLength(& p), RL2);
    
    String_Dtor(& p);
    String_Dtor(& o);
    return 0;
}

