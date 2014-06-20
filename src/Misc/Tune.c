#include "Tune.h" 
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../Core/OO.h"

static const char* Tune_PitchName[] = 
    {
        "C", "C#", "D", "D#", "E", "F", "F#",
        "G", "G#", "A", "A#", "B"
    };

int Tune_SPNToPitch(String* Sorc)
{
    int CmpR = 0;
    int SLen = String_GetLength(Sorc);
    int NameID;
    char* SData = Sorc->Data;
    
    if (SData[1] == '#')
    {
        if (SLen < 3)
            return -10086;
        CmpR = 2;
    } else
    {
        if (SLen < 2)
            return -10086;
        CmpR = 1;
    }
    
    for (NameID = 0; NameID < 12; ++NameID)
    {
        if (! (strncmp(SData, Tune_PitchName[NameID], CmpR)))
            break;
    }
    return (atoi(SData + CmpR) + 1) * 12 + NameID;
}

float Tune_FreqToPitch(float Freq)
{
    if (Freq <= 5)
        return -10086;
    return 69.0f + 12.0f * log2f(Freq / 440.0f);
}

#if 0
#include "_Tune.rc"
#endif
#define _RTAddress "Misc/_Tune.rc"
#define _ClassName
#define _Attr 1

#define _T1 Float
#include "../Core/RTemplate.h"

#define _T1 Int
#include "../Core/RTemplate.h"