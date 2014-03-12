#include <stdio.h>
#include "Structure/String.h"
#include "Misc/Convert.h"
#include "Misc/Sort.h"

int main(void)
{
    float ListF[6] = {9.333, 4.234, 1.234, 6.2343, 3.234, 1.789};
    double ListD[6] = {9.333, 4.234, 1.234, 6.2343, 3.234, 1.789};
    int ListI[6] = {9, 4, 1, 6, 3, 1};
    #define List ListI
    int SIndex[6];
    Sort_DecIndex_Int(List, SIndex, List, 6);
    Sort_Inc_Int(List, List, 6);
    int i;
    for(i = 0; i < 6; i ++)
    {
        printf("%d\t%d\n", List[i], SIndex[i]);
    }
    return 0;
}

