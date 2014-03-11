#ifndef PMATCH_H
#define PMATCH_H

#include "Array.h"
#include "Transition.h"
#include "../Core/OO.h"

#if 0
#include "_PMatch.h"
#endif
#define _RTAddress "../Structure/_PMatch.h"
#define _ClassName PMatch_
#define _Attr 2

#define _T1 Float
#define _T2 Float
#include "../Core/RTemplate.h"

#define _T1 Float
#define _T2 Double
#include "../Core/RTemplate.h"

#define _T1 Double
#define _T2 Float
#include "../Core/RTemplate.h"

#define _T1 Double
#define _T2 Double
#include "../Core/RTemplate.h"

//Default
#define PMatch PMatch_Double_Double
#define PMatch_Ctor PMatch_Double_Double_Ctor
#define PMatch_Dtor PMatch_Double_Double_Dtor
#define PMatch_AddPair PMatch_Double_Double_AddPair
#define PMatch_Clear PMatch_Double_Double_Clear
#define PMatch_Print PMatch_Double_Double_Print
#define PMatch_Query PMatch_Double_Double_Query

#endif

