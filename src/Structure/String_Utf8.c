#include <string.h>
#include "String_Utf8.h"
#include "UtfString.h"
#include "Array.h"
#include "../Core/OO.h"

RCtor(String_Utf8)
{
    String_Ctor(& (This -> _Base));
    This -> WordNum = 0;
    RInit(String_Utf8);
}

RDtor(String_Utf8)
{
    String_Dtor(& (This -> _Base));
}

void String_Utf8_AllocWordNum(String_Utf8* This, int WordNum)
{
    String_Utf8_AllocLength(This, WordNum * 6);
}

void String_Utf8_SetChars(String_Utf8* This, const char* Chars)
{
    String_SetChars(& (This -> _Base), Chars);
    This -> WordNum = strnum_utf8(Chars);
}

void String_Utf8_SetCharsN(String_Utf8* This, const char* Chars, int WordNum)
{
    const char* Chars_End = Chars;
    int i;
    for(i = 0; i < WordNum &&
               * Chars_End;
                ++i, Chars_End = next_char_utf8(Chars_End));
    
    int DataLength = Chars_End - Chars;
    
    String_AllocLength(& (This -> _Base), DataLength);
    
    memcpy(This -> _Base.Data, Chars, DataLength);
    
    This -> _Base.Data_Index = DataLength - 1;
    This -> WordNum = i;
}

void String_Utf8_Copy(String_Utf8* This, String_Utf8* Sorc)
{
    String_Copy(& (This -> _Base), & (Sorc -> _Base));
    This -> WordNum = Sorc -> WordNum;
}

int String_Utf8_GetWordNum(String_Utf8* This)
{
    return This -> WordNum;
}

void String_Utf8_GetWord(String_Utf8* This, String_Utf8* Dest, int Index)
{
    const char* Curr = This -> _Base.Data;
    for(int i = 0; i < Index; ++i, Curr = next_char_utf8(Curr))
        RAssert(* Curr);
    int WordLength = GetWordLength_Utf8(Curr[0]);
    String_AllocLength(& (Dest -> _Base), WordLength);
    memcpy(Dest -> _Base.Data, Curr, WordLength);
    Dest -> WordNum = 1;
}

void String_Utf8_SetWord(String_Utf8* This, int Index, String_Utf8* Data)
{
    RAssert(Data -> WordNum > 0);
    
    char* Curr = This -> _Base.Data;
    int RIndex = 0;
    
    for(int i = 0; i < Index; ++i, Curr = next_char_utf8(Curr), ++RIndex)
        RAssert(* Curr);
    int WordLengthT = GetWordLength_Utf8(Curr[0]);
    int WordLengthD = GetWordLength_Utf8(Data -> _Base.Data[0]);
    
    int DeltaLength = WordLengthD - WordLengthT;
    
    if(WordLengthD - WordLengthT)
    {
        int TLen = String_GetLength(&(This -> _Base));
        int CpLen = TLen - RIndex - WordLengthT;
        char Buffer[CpLen];
        
        // Cp to buffer
        memcpy(Buffer, Curr + WordLengthT, CpLen);
        String_AllocLength(& (This -> _Base), TLen + DeltaLength);
        Curr = This -> _Base.Data + RIndex;
        memcpy(Curr, Data -> _Base.Data, WordLengthD);
        memcpy(Curr + WordLengthD, Buffer, CpLen);
        
        // Update length.
        This -> _Base.Data_Index = TLen + DeltaLength - 1;
    }
    else
        memcpy(Curr, Data -> _Base.Data, WordLengthT);
}

void String_Utf8_Join(String_Utf8* This, String_Utf8* Sorc)
{
    String_Join(& (This -> _Base), & (Sorc -> _Base));
    This -> WordNum += Sorc -> WordNum;
}

void String_Utf8_JoinChars(String_Utf8* This, char* Sorc)
{
    String_JoinChars(& (This -> _Base), Sorc);
    This -> WordNum += strnum_utf8(Sorc);
}

int String_Utf8_EqualN(String_Utf8* This, String_Utf8* Sorc, int w)
{
    return (w == Sorc -> WordNum) && 
           (! strwcmp_utf8(This -> _Base.Data, Sorc -> _Base.Data, w));
}

int String_Utf8_EqualNChars(String_Utf8* This, char* Sorc, int w)
{
    return ! strwcmp_utf8(This -> _Base.Data, Sorc, w);
}

int String_Utf8_InStrFrom(String_Utf8* This, String_Utf8* Part, int From)
{
    int CurrWord = From;
    
    Array_Push(char, This -> _Base.Data, 0);
    --This -> _Base.Data_Index;
    
    Array_Push(char, Part -> _Base.Data, 0);
    --Part -> _Base.Data_Index;
    
    char* Curr = This -> _Base.Data;
    
    int ThisLen = String_Utf8_GetLength(This);
    int PartLen = String_Utf8_GetLength(Part);
    
    for(int i = 0; i < From; ++i)
        Curr = next_char_safe_utf8(Curr, Curr + ThisLen);
    
    do
    {
        for(int j = 0; j < PartLen; ++j)
        {
            if(Part -> _Base.Data[j] != Curr[j])
                goto cont;
        }
        return CurrWord;
        cont:;
        ++CurrWord;
    } while((Curr = next_char_safe_utf8(Curr, Curr + ThisLen)));
    
    return -1;
}

int String_Utf8_InStr(String_Utf8* This, String_Utf8* Part)
{
    return String_Utf8_InStrFrom(This, Part, 0);
}

int String_Utf8_InStrRevFrom(String_Utf8* This, String_Utf8* Part, int From)
{
    int CurrWord = From;
    
    Array_Push(char, This -> _Base.Data, 0);
    --This -> _Base.Data_Index;
    
    Array_Push(char, Part -> _Base.Data, 0);
    --Part -> _Base.Data_Index;
    
    char* Curr = This -> _Base.Data;
    
    int ThisLen = String_Utf8_GetLength(This);
    int PartLen = String_Utf8_GetLength(Part);
    
    for(int i = 0; i < From; ++i)
        Curr = next_char_safe_utf8(Curr, Curr + ThisLen);
    
    do
    {
        for(int j = 0; j < PartLen; ++j)
        {
            if(Part -> _Base.Data[j] != Curr[j])
                goto cont;
        }
        return CurrWord;
        cont:;
        --CurrWord;
    } while((Curr = prev_char_safe_utf8(Curr, This -> _Base.Data)));
    
    return -1;
}

int String_Utf8_InStrRev(String_Utf8* This, String_Utf8* Part)
{
    return String_Utf8_InStrRevFrom(This, Part, String_Utf8_GetWordNum(This));
}

void Mid_Utf8(String_Utf8* Dest, String_Utf8* Sorc, int From, int Count)
{
    char* Begin = Sorc -> _Base.Data;
    char* End = NULL;
    
    for(int i = 0; i < From && Begin; ++i)
        Begin = next_char_safe_utf8(Begin, 
                                    Sorc -> _Base.Data + 
                                    Sorc -> _Base.Data_Index + 1);
    RAssert(Begin);
    End = Begin;
    
    for(int i = 0; i < Count && End; ++i)
        End = next_char_safe_utf8(End, 
                                  Sorc -> _Base.Data + 
                                  Sorc -> _Base.Data_Index + 1);
    RAssert(End);
    
    int MidLen = End - Begin;
    String_Utf8_AllocLength(Dest, MidLen);
    memcpy(Dest -> _Base.Data, Begin, MidLen);
    
    // Update length.
    Dest -> _Base.Data_Index = MidLen - 1;
    Dest -> WordNum = Count;
}

void MidFrom_Utf8(String_Utf8* Dest, String_Utf8* Sorc, int From)
{
    char* Begin = Sorc -> _Base.Data;
    char* End = Sorc -> _Base.Data + Sorc -> _Base.Data_Index + 1;
    
    for(int i = 0; i < From; ++i)
        Begin = next_char_safe_utf8(Begin, 
                                    End);
    RAssert(Begin);
    
    int MidLen = End - Begin;
    String_Utf8_AllocLength(Dest, MidLen);
    
    memcpy(Dest -> _Base.Data, Begin, MidLen);
    Dest -> _Base.Data_Index = MidLen - 1;
    Dest -> WordNum = Sorc -> WordNum - From;
}

void Right_Utf8(String_Utf8* Dest, String_Utf8* Sorc, int Count)
{
    char* End = Sorc -> _Base.Data + Sorc -> _Base.Data_Index + 1;
    char* Begin = End;
    for(int i = 0; i < Count; ++i)
        Begin = prev_char_safe_utf8(Begin, 
                                    Sorc -> _Base.Data);
    RAssert(Begin);
    
    int Len = End - Begin;
    String_Utf8_AllocLength(Dest, Len);
    
    memcpy(Dest -> _Base.Data, Begin, Len);
    Dest -> _Base.Data_Index = Len - 1;
    Dest -> WordNum = Count;
}

void Left_Utf8(String_Utf8* Dest, String_Utf8* Sorc, int Count)
{
    char* Begin = Sorc -> _Base.Data;
    char* End = Begin;
    for(int i = 0; i < Count; ++i)
        End = next_char_safe_utf8(End, 
                                  Sorc -> _Base.Data + 
                                  Sorc -> _Base.Data_Index + 1);
    RAssert(End);
    
    int Len = End - Begin;
    String_Utf8_AllocLength(Dest, Len);
    
    memcpy(Dest -> _Base.Data, Begin, Len);
    Dest -> _Base.Data_Index = Len - 1;
    Dest -> WordNum = Count;
}

void UpperCase_Utf8(String_Utf8* Dest, String_Utf8* Sorc)
{
    String_Utf8_Copy(Dest, Sorc);
    char* Curr = Dest -> _Base.Data;
    
    do
    {
        if(Curr[0] >= 'a' || Curr[0] <= 'z')
            Curr[0] += ('A' - 'a');
    } while((Curr = next_char_safe_utf8(Curr, 
                                        Dest -> _Base.Data + 
                                        Dest -> _Base.Data_Index + 1)));
}

void LowerCase_Utf8(String_Utf8* Dest, String_Utf8* Sorc)
{
    String_Utf8_Copy(Dest, Sorc);
    char* Curr = Dest -> _Base.Data;
    
    do
    {
        if(Curr[0] >= 'A' || Curr[0] <= 'Z')
            Curr[0] -= ('A' - 'a');
    } while((Curr = next_char_safe_utf8(Curr, 
                                        Dest -> _Base.Data + 
                                        Dest -> _Base.Data_Index + 1)));
}

void Trim_Utf8(String_Utf8* Dest, String_Utf8* Sorc)
{
    char* Begin = Sorc -> _Base.Data;
    char* End = Sorc -> _Base.Data + Sorc -> _Base.Data_Index;
    int LSkip, RSkip;
    
    for(LSkip = 0; Begin && (Begin[0] == ' ' || Begin[0] == '\t'); 
        ++LSkip, Begin = next_char_safe_utf8(Begin, End));
    if(! Begin)
        return;
    
    for(RSkip = 0; End && (End[0] == ' ' || End[0] == '\t'); 
        ++RSkip, End = prev_char_safe_utf8(End, Begin));
    if(! End)
        return;
    
    End = next_char_utf8(End);
    
    String_Utf8_AllocLength(Dest, End - Begin);
    
    Dest -> WordNum = Sorc -> WordNum - LSkip - RSkip;
    Dest -> _Base.Data_Index = End - Begin - 1;
    
    memcpy(Dest -> _Base.Data, Begin, End - Begin);
}

void LTrim_Utf8(String_Utf8* Dest, String_Utf8* Sorc)
{
    char* Begin = Sorc -> _Base.Data;
    char* End = Sorc -> _Base.Data + Sorc -> _Base.Data_Index;
    int LSkip;
    
    for(LSkip = 0; Begin && (Begin[0] == ' ' || Begin[0] == '\t'); 
        ++LSkip, Begin = next_char_safe_utf8(Begin, End));
    if(! Begin)
        return;
    
    End = next_char_utf8(End);
    
    String_Utf8_AllocLength(Dest, End - Begin);
    
    Dest -> WordNum = Sorc -> WordNum - LSkip;
    Dest -> _Base.Data_Index = End - Begin - 1;
    
    memcpy(Dest -> _Base.Data, Begin, End - Begin);
}

void RTrim_Utf8(String_Utf8* Dest, String_Utf8* Sorc)
{
    char* Begin = Sorc -> _Base.Data;
    char* End = Sorc -> _Base.Data + Sorc -> _Base.Data_Index;
    int RSkip;
    
    for(RSkip = 0; End && (End[0] == ' ' || End[0] == '\t'); 
        ++RSkip, End = prev_char_safe_utf8(End, Begin));
    if(! End)
        return;
    
    End = next_char_utf8(End);
    
    String_Utf8_AllocLength(Dest, End - Begin);
    
    Dest -> WordNum = Sorc -> WordNum - RSkip;
    Dest -> _Base.Data_Index = End - Begin - 1;
    
    memcpy(Dest -> _Base.Data, Begin, End - Begin);
}