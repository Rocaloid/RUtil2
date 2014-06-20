/*
#include "Tune.h" 
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static const char* Tune_PitchName[] = 
    {
        "C", "C#", "D", "D#", "E", "F", "F#",
        "G", "G#", "A", "A#", "B"
    };

int Tune_PitchToSPN_Int(String* Dest, int PitchNum)
{
    char StrBuffer[5];
    int RetV = snprintf(StrBuffer, 5, "%s%d", 
                        Tune_PitchName[PitchNum % 12], (PitchNum / 12 - 1));
    if(! ((RetV > 0) && (RetV < 5)))
        return 1;
    StrBuffer[4] = '\0';
    String_SetChars(Dest, StrBuffer);
    return 0;
}

int Tune_PitchToSPN_Float(String* Dest, float PitchNum_f)
{
    char StrBuffer[5];
    int PitchNum = round(PitchNum_f);
    int RetV = snprintf(StrBuffer, 5, "%s%d", 
                        Tune_PitchName[PitchNum % 12], (PitchNum / 12 - 1));
    if(! ((RetV > 0) && (RetV < 5)))
        return 1;
    StrBuffer[4] = '\0';
    String_SetChars(Dest, StrBuffer);
    return 0;
}

int Tune_SPNToPitch(String* Sorc)
{
    int CmpR = 0;
    int SLen = String_GetLength(Sorc);
    int NameID;
    char* SData = Sorc->Data;
    
    if(SData[1] == '#')
    {
        if(SLen < 3)
            return -10086;
        CmpR = 2;
    }
    else
    {
        if(SLen < 2)
            return -10086;
        CmpR = 1;
    }
    
    for(NameID = 0; NameID < 12; ++NameID)
    {
        if(! (strncmp(SData, Tune_PitchName[NameID], CmpR)))
            break;
    }
    return (atoi(SData + CmpR) + 1) * 12 + NameID;
}

float Tune_FreqToPitch(float Freq)
{
    if(Freq <= 5)
        return -10086;
    return 69.0f + 12.0f * log2(Freq / 440.0f);
}
*/
