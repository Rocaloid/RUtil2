#include <stdint.h>
#include "../Structure/String.h"

#include "Base64.h" // Own include.

static const char RB64_Table[]=
    {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 
    'w', 'x', 'y', 'z', '0', '1', '2', '3', 
    '4', '5', '6', '7', '8', '9', '+', '/' 
    };


int Base64_Encode(String *Dest, void *SSrc, int SLen)
{
    if(!SSrc) return 0;
    
    int DLen=((SLen+2)/3) << 2;
    char *Src=(char *)SSrc;
    char *SEnd=Src+SLen;
    
    String_AllocLength(Dest, DLen+1);
    
    char *DData=String_GetChars(Dest);
    if(!DData) return -1;
    
    /* 0x30 -> 00110000
       0x3C -> 00111100
       0x3F -> 00111111 */
    while(SEnd-Src>=3)
    {
        *(DData++)=RB64_Table[(*Src >> 2)];
        *(DData++)=RB64_Table[((*Src << 4) & 0x30) | (*(Src+1) >> 4)];
        *(DData++)=RB64_Table[((*(Src+1) << 2) & 0x3C) | (*(Src+2) >> 6)];
        *(DData++)=RB64_Table[*(Src+2) & 0x3F];
        Src+=3;
    }
    
    if(SEnd-Src>0)
    {
        *(DData++)=RB64_Table[(*Src >> 2)];  
        if (SEnd-Src==2)
        {  
            *(DData++)=RB64_Table[((*Src << 4) & 0x30 ) | (*(Src+1) >> 4)];  
            *(DData++)=RB64_Table[(*(Src+1) << 2) & 0x3C];   
            *(DData++)='=';  
        }
        else if (SEnd-Src==1)
        {  
            *(DData++)=RB64_Table[(*(Src+1) << 4) & 0x30];  
            *(DData++)='=';  
            *(DData++)='=';  
        }
    }
    
    *(DData)='\0';  
    return DLen;
}

int Base64_Decode(void *Dest, String *SSrc)
{
    
}