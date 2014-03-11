#include <stdio.h>
#include "Structure/String.h"

int main(void)
{
    String a;
    String b;
    RNew(String, & a, & b);
    
    String_SetChars(& a, "asdfsf from a string.");
    String_SetChars(& b, "string2.");
    String_Join(& a, & b);
    printf("%s\n", String_GetChars(& a));
    
    RDelete(& a, & b);
    return 0;
}

