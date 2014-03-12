#include <stdio.h>
#include "Structure/String.h"
#include "Misc/Convert.h"

int main(void)
{
    String a, b, c;
    RNew(String, & a, & b, & c);
    
    String_SetChars(& a, "asdfsf from a string.");
    String_SetChars(& b, "string2.");
    String_Join(& a, & b);
    String_SetChars(& c, "234.234324");
    double x = CDoubleStr(& c);
    Mid(& c, & a, 5, 10);
    printf("%s\n", String_GetChars(& c));
    printf("%lf, %d\n", x, InStr(& a, & b));
    
    RDelete(& a, & b, & c);
    return 0;
}

