#include <malloc.h>
#include <stdarg.h>
#include "RAlloc.h"
#include "OO.h"

void* RAlloc(int Size)
{
    return malloc(Size);
}

void* RAlign(int Align, int Size)
{
    return memalign(Align, Size);
}

void __RFree(void* a, ...)
{
    void* Ptr;
    va_list Args;
    va_start(Args, a);
    
    //First
    free(a);
    while(1)
    {
        Ptr = va_arg(Args, void*);
        //End
        if((int)Ptr == - 1)
            break;
        free(Ptr);
    }
    
    va_end(Args);
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

