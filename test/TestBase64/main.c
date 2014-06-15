#include <stdio.h>
#include "Core/RAlloc.h"
#include "Structure/String.h"
#include "Misc/Base64.h"

static const char str[]="What a fucky day! Isn't it?";

int main()
{
    String o;
    String_Ctor(&o);
    Base64_Encode(&o, (void *)str, sizeof(str));
    printf("%s\n", o.Data);
    return 0;
}
