#include <stdlib.h>
#if defined(__APPLE__)
#include <malloc/malloc.h>
#endif
#include <stdarg.h>
#include "RAlloc.h"
#include "OO.h"

#if defined(__APPLE__)
void *aligned_malloc( size_t size, int align )
{
    void *mem = malloc( size + (align-1) + sizeof(void*) );

    char *amem = ((char*)mem) + sizeof(void*);
    amem += align - ((uintptr_t)amem & (align - 1));

    ((void**)amem)[-1] = mem;
    return amem;
}

void aligned_free( void *mem )
{
    free( ((void**)mem)[-1] );
}
#endif

void* RAlloc(int Size)
{
    void* ret = malloc(Size);
    return ret;
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
        if(Ptr == (void *)-1)
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

