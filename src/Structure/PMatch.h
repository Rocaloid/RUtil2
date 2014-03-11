#ifndef PMATCH_H
#define PMATCH_H

#include "Array.h"
#include "Transition.h"
#include "../Core/OO.h"

#if 0
#include "_PMatch.h"
#endif
#define _RTAddress "../Structure/_PMatch.h"
#define _ClassName PMatch
#define _Attr 2

#define _T1 float
#define _T2 float
#include "../Core/RTemplate.h"

#define _T1 float
#define _T2 double
#include "../Core/RTemplate.h"

#define _T1 double
#define _T2 float
#include "../Core/RTemplate.h"

#define _T1 double
#define _T2 double
#include "../Core/RTemplate.h"

//Default methods
#define PMatch_AddPair PMatch_double_double_AddPair
#define PMatch_Clear PMatch_double_double_Clear
#define PMatch_Print PMatch_double_double_Print
#define PMatch_Query PMatch_double_double_Query

#endif

