#include <stdio.h>
#include "Structure/String.h"

int main(void)
{
    String a, b, c;
    RNew(String, & a, & b, & c);
    
    String_SetChars(& a, "asdfsf from a string.");
    String_SetChars(& b, "string2.");
    String_Join(& a, & b);
    Mid(& c, & a, 5, 10);
    printf("%s\n", String_GetChars(& c));
    
    RDelete(& a, & b, & c);
    return 0;
}

