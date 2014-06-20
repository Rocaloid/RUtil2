#ifndef RUTIL2_TUNE_H
#define RUTIL2_TUNE_H

#include "../Core/OO.h"
#include "../Structure/String.h"

// Return PitchNum.
// If an error occurrs, -10086 is returned.
int Tune_SPNToPitch(String* Sorc);

// Return PitchNum.
// If an error occurrs, -10086 is returned.
float Tune_FreqToPitch(float Freq);

#if 0
#include "_Tune.h"
#endif
#ifdef __RUtil2_Install
#define _RTAddress "RUtil2/Misc/_Tune.h"
#else
#define _RTAddress "Misc/_Tune.h"
#endif
#define _ClassName
#define _Attr 1

#define _T1 Float
#include "../Core/RTemplate.h"

#define _T1 Int
#include "../Core/RTemplate.h"

#endif //RUTIL2_TUNE_H