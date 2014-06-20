#include <stdio.h>

#include "Structure/String.h"
#include "Misc/Tune.h"

int PTTNr = 0;

int PitchToolTest(float Freq)
{
    String s;
    String_Ctor(& s);
    
    printf("    PtichToolTest Nr = %d: Freq = %f, Pitch = %f", ++PTTNr, Freq, Tune_FreqToPitch(Freq));
    Tune_PitchToSPN_Float(& s, Tune_FreqToPitch(Freq));
    printf(", Name = %s", String_GetChars(& s));
    
    printf(", RetPit = %d", Tune_SPNToPitch(& s));
    
    printf(".\n");
    String_Dtor(& s);
    return 0;
}

int main()
{
    printf("RUtil2 Tune Test: \n");

    if(PitchToolTest(441.0f)) return 1;
    
    return 0;
}