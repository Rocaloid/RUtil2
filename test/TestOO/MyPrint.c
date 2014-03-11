#include <stdio.h>
#include "MyPrint.h"
#include "RUtil/Core/OO.h"

#if 0
#include "_MyPrint.rc"
#endif
#define _RTAddress "_MyPrint.rc"
#define _ClassName
#define _Attr 1

#define _T1 float
#include "RUtil/Core/RTemplate.h"

#define _T1 double
#include "RUtil/Core/RTemplate.h"

void Check_float(float Sorc)
{
    printf("Float is %f\n", Sorc);
}

void Check_double(double Sorc)
{
    printf("Double is %.9lf\n", Sorc);
}

