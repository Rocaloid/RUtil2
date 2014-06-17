#include "Base64.h"
#include <string.h>
#include <stdint.h>
#include <assert.h>

static char RB64_Table[] =
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

static int RB64_Decode_Table[] =
{
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 0   - 15
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 16  - 31
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63, // 32  - 47
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1, // 48  - 63
    -1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, // 64  - 79
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, // 80  - 95
    -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, // 96  - 111
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1, // 112 - 127
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 128 - 143
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 144 - 159
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 160 - 175
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 176 - 191
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 192 - 207
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 208 - 223
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 224 - 239
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1  // 240 - 255
};

int Base64_DecodeSize(int StrSize)
{
    return ((StrSize + 3) >> 2) * 3;
}

int Base64_EncodeSize(int DataSize)
{
    return ((DataSize + 2) / 3) << 2;
}

int Base64_Encode(String* Dest, void* Sorc, int Size)
{
    if(! Sorc) return 0;
    
    int Ret = Base64_EncodeSize(Size);
    char* CSorc = (char*)Sorc;
    char* CEnd  = (char*)Sorc + Size;
    
    String_AllocLength(Dest, Ret);
    
    char* DData = (char*)Dest -> Data;
    if(! DData) return - 1;
    
    /* 0x30 -> 00110000
       0x3C -> 00111100
       0x3F -> 00111111 */
    while(CEnd - CSorc > 2)
    {
        *(DData ++) = RB64_Table[(*CSorc >> 2)];
        *(DData ++) = RB64_Table[((*CSorc << 4) & 0x30)   | (CSorc[1] >> 4)];
        *(DData ++) = RB64_Table[((CSorc[1] << 2) & 0x3C) | (CSorc[2] >> 6)];
        *(DData ++) = RB64_Table[CSorc[2] & 0x3F];
        CSorc += 3;
    }
    
    if(CEnd - CSorc > 0)
    {
        *(DData ++) = RB64_Table[(*CSorc >> 2)];  
        if(CEnd - CSorc == 2)
        {  
            *(DData ++) = RB64_Table[((*CSorc << 4) & 0x30 ) | (CSorc[1] >> 4)];
            *(DData ++) = RB64_Table[(CSorc[1] << 2) & 0x3C];   
            *(DData ++) = '=';
        }
        else if(CEnd - CSorc == 1)
        {  
            *(DData ++) = RB64_Table[(CSorc[1] << 4) & 0x30];  
            *(DData ++) = '=';
            *(DData ++) = '=';
        }
    }
    
    Dest -> Data_Index = Ret - 1;
    
    return Ret;
}

int Base64_Decode(void* Dest, String* Sorc)
{
    assert(Dest);
    unsigned char* CDest = (unsigned char*)Dest;
    int Ret = 0;
    CDest[0] = 0;
    
    int SLen = String_GetLength(Sorc);
    if (SLen < 4 || SLen % 4 != 0) return - 1;
    unsigned char* Input_Chars = (unsigned char*)Sorc -> Data;
    
    // 0xFC -> 11111100
    // 0x03 -> 00000011
    // 0xF0 -> 11110000
    // 0x0F -> 00001111
    // 0xC0 -> 11000000
    unsigned char* Curr;
    unsigned char* SEnd = Input_Chars + SLen;
    for(Curr = Input_Chars; Curr < SEnd; Curr += 4)
    {
        *CDest++ = ((RB64_Decode_Table[Curr[0]] << 2) & 0xFC) | 
                   ((RB64_Decode_Table[Curr[1]] >> 4) & 0x03);
        *CDest++ = ((RB64_Decode_Table[Curr[1]] << 4) & 0xF0) |
                   ((RB64_Decode_Table[Curr[2]] >> 2) & 0x0F);
        *CDest++ = ((RB64_Decode_Table[Curr[2]] << 6) & 0xC0) |
                   (RB64_Decode_Table[Curr[3]]);
        Ret += 3;
    }
    
    if(*(Input_Chars + SLen - 2) == '=')
    {
        *(CDest - 2) = '\0';
        Ret -= 2;
    }
    else if(*(Input_Chars + SLen - 1) == '=')
    {
        *(CDest - 1) = '\0';
        Ret -= 1;
    }
    
    return Ret - 1;
}

