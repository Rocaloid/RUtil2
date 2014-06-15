#include <stdio.h>
#include <Misc/Base64.h>

int main()
{
    String o;
    Base64_Encode(&o, "Hello world!g", 13);
    printf("%s\n", o.Data);
    return 0;
}
