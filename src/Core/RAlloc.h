#ifndef RALLOC_H
#define RALLOC_H

#include "OO.h"

void* RAlloc(int Size);
void RFree(void* Ptr);

#define RAlloc_Class(Name, Size) \
    (Name*)__RAlloc_Class(Size, sizeof(Name), __ClassID_##Name##__);
void* __RAlloc_Class(int Size, int UnitSize, int ClassID);

#if 0
#include "_RAlloc.h"
#endif
#ifdef __RUtil2_Install
#define _RTAddress "RUtil2/Core/_RAlloc.h"
#else
#define _RTAddress "Core/_RAlloc.h"
#endif

#define _ClassName
#define _Attr 1

#include "Include_T1AllTypes.h"

#endif

