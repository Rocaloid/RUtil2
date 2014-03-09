#include "String.h"

RCtor(String)
{
    Array_Ctor(char, This -> Data);
    RInit(String);
}

RDtor(String)
{
    Array_Dtor(char, This -> Data);
}

