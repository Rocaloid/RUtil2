#include <malloc.h>
#include "RAlloc.h"
#include "OO.h"

void* RAlloc(int Size)
{
    return malloc(Size);
}

void RFree(void* Ptr)
{
    free(Ptr);
}

void* __RAlloc_Class(int Size, int UnitSize, int ClassID)
{
    return malloc(Size * UnitSize);
}

#if 0
#include "_RAlloc.rc"
#endif
#define _RTAddress "Core/_RAlloc.rc"

#define _ClassName
#define _Attr 1

#include "Include_T1AllTypes.h"

