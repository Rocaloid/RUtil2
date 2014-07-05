#include "String_Utf8.h"
#include <string.h>
#include "UtfString.h"
#include "../Core/OO.h"

RCtor(String_Utf8)
{
    String_Ctor(& (This -> _Base));
    This -> WordNum = 0;
    RInit(String_Utf8);
}

RDtor(String_Utf8)
{
    String_Dtor(& (This -> _Base));
}

void String_Utf8_SetChars(String_Utf8* This, char* Chars)
{
    String_SetChars(& (This -> _Base), Chars);
    This -> WordNum = strlen_utf8(Chars);
}