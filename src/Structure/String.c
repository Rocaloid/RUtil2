#include "String.h"
#include <string.h>

RCtor(String)
{
    Array_Ctor(char, This -> Data);
    RInit(String);
}

RDtor(String)
{
    Array_Dtor(char, This -> Data);
}

void String_SetChars(String* This, char* Chars)
{
    int Len = strlen(Chars);
    Array_Resize(char, This -> Data, Len);
    memcpy(This -> Data, Chars, Len);
    This -> Data_Index = Len - 1;
}

void String_SetCharsN(String* This, char* Chars, int Length)
{
    Array_Resize(char, This -> Data, Length);
    memcpy(This -> Data, Chars, Length);
    This -> Data_Index = Length - 1;
}

char* String_GetChars(String* This)
{
    Array_Push(char, This -> Data, 0);
    This -> Data_Index --;
    return This -> Data;
}

void String_Copy(String* This, String* Sorc)
{
    Array_Resize(char, This -> Data, Sorc -> Data_Index + 1);
    memcpy(This -> Data, Sorc -> Data, Sorc -> Data_Index + 1);
    This -> Data_Index = Sorc -> Data_Index;
}

int String_GetLength(String* This)
{
    return This -> Data_Index + 1;
}

void String_AllocLength(String* This, int Length)
{
    Array_Resize(char, This -> Data, Length);
}

char String_GetChar(String* This, int Index)
{
    return This -> Data[Index];
}

void String_SetChar(String* This, int Index, char Data)
{
    This -> Data[Index] = Data;
}

void String_Join(String* This, String* Sorc)
{
    Array_Resize(char, This -> Data, 
        This -> Data_Index + Sorc -> Data_Index + 2 + This -> Data_Index / 10);
    memcpy(This -> Data + This -> Data_Index + 1, Sorc -> Data,
        Sorc -> Data_Index + 1);
    This -> Data_Index += Sorc -> Data_Index + 1;
}

void String_JoinChars(String* This, char* Sorc)
{
    int Len = strlen(Sorc);
    Array_Resize(char, This -> Data,
        This -> Data_Index + Len + 1 + This -> Data_Index / 10);
    memcpy(This -> Data + This -> Data_Index + 1, Sorc, Len);
    This -> Data_Index += Len;
}

int String_Equal(String* This, String* Sorc)
{
    return (This -> Data_Index == Sorc -> Data_Index) &&
           (! strncmp(This -> Data, Sorc -> Data, This -> Data_Index + 1));
}

int String_EqualChars(String* This, char* Sorc)
{
    if(strlen(Sorc) == (size_t)This -> Data_Index + 1)
        return ! strncmp(This -> Data, Sorc, This -> Data_Index + 1);
    return 0;
}
/*
//------------------------------------------------------------

void Mid(String* Dest, String* Sorc, int From, int Count)
{
    int i;
    if(Count + From > Sorc -> Data_Index)
        Count = Sorc -> Data_Index - From + 1;
    if(Count < 0)
        Count = 0;
    String_AllocLength(Dest, Count);
    for(i = 0;i < Count;i ++)
        Dest -> Data[i] = Sorc -> Data[From + i];
    Dest -> Data_Index = Count - 1;
}

void MidFrom(String* Dest, String* Sorc, int From)
{
    int i;
    int Count = Sorc -> Data_Index - From + 1;
    if(Count < 0)
        Count = 0;
    String_AllocLength(Dest, Count);
    for(i = 0;i < Count;i ++)
        Dest -> Data[i] = Sorc -> Data[From + i];
    Dest -> Data_Index = Count - 1;
}

void Right(String* Dest, String* Sorc, int Count)
{
    int i;
    if(Sorc -> Data_Index - Count < - 1)
        Count = Sorc -> Data_Index + 1;
    int From = Sorc -> Data_Index + 1 - Count;
    if(Count < 0)
        Count = 0;
    String_AllocLength(Dest, Count);
    for(i = 0;i < Count;i ++)
        Dest -> Data[i] = Sorc -> Data[From + i];
    Dest -> Data_Index = Count - 1;
}

void Left(String* Dest, String* Sorc, int Count)
{
    int i;
    if(Count > Sorc -> Data_Index + 1)
        Count = Sorc -> Data_Index + 1;
    if(Count < 0)
        Count = 0;
    String_AllocLength(Dest, Count);
    for(i = 0;i < Count;i ++)
        Dest -> Data[i] = Sorc -> Data[i];
    Dest -> Data_Index = Count - 1;
}

void UpperCase(String* Dest, String* Sorc)
{
    int i;
    int Len = Sorc -> Data_Index + 1;
    String_AllocLength(Dest, Len);
    for(i = 0;i < Len;i ++)
        if(Sorc -> Data[i] >= 'a' && Sorc -> Data[i] <= 'z')
            Dest -> Data[i] = Sorc -> Data[i] + ('A' - 'a');
        else
            Dest -> Data[i] = Sorc -> Data[i];
    Dest -> Data_Index = Len - 1;
}

void LowerCase(String* Dest, String* Sorc)
{
    int i;
    int Len = Sorc -> Data_Index + 1;
    String_AllocLength(Dest, Len);
    for(i = 0;i < Len;i ++)
        if(Sorc -> Data[i] >= 'A' && Sorc -> Data[i] <= 'Z')
            Dest -> Data[i] = Sorc -> Data[i] + ('a' - 'A');
        else
            Dest -> Data[i] = Sorc -> Data[i];
    Dest -> Data_Index = Len - 1;
}

int InStrFrom(String* Whole, String* Part, int From)
{
    int i, j;
    int End = Whole -> Data_Index - Part -> Data_Index;
    int PartLen = Part -> Data_Index + 1;

    Array_Push(char, Whole -> Data, 0);
    Whole -> Data_Index --;
    Array_Push(char, Part -> Data, 0);
    Part -> Data_Index --;

    for(i = From;i <= End;i ++)
    {
        for(j = 0;j < PartLen;j ++)
            if(Part -> Data[j] != Whole -> Data[i + j])
                goto cont;
        return i;
        cont:;
    }
    return -1;
}

int InStr(String* Whole, String* Part)
{
    return InStrFrom(Whole, Part, 0);
}

int InStrRevFrom(String* Whole, String* Part, int From)
{
    int i, j;
    int End = Whole -> Data_Index - Part -> Data_Index;
    int PartLen = Part -> Data_Index + 1;
    From = From > End ? End : From;

    Array_Push(char, Whole -> Data, 0);
    Whole -> Data_Index --;
    Array_Push(char, Part -> Data, 0);
    Part -> Data_Index --;

    for(i = From;i >= 0;i --)
    {
        for(j = 0;j < PartLen;j ++)
            if(Part -> Data[j] != Whole -> Data[i + j])
                goto cont;
        return i;
        cont:;
    }
    return -1;
}

int InStrRev(String* Whole, String* Part)
{
    return InStrRevFrom(Whole, Part, Whole -> Data_Index + 1);
}

void Trim(String* Dest, String* Sorc)
{
    int Start, End, i, SorcLen, RetLen;
    SorcLen = Sorc -> Data_Index + 1;
    Start = 0;
    End = 0;
    for(i = 0;i < SorcLen;i ++)
        if(Sorc -> Data[i] != ' ' && Sorc -> Data[i] != '\t')
        {
            Start = i;
            break;
        }
    for(i = SorcLen - 1;i >= 0;i --)
        if(Sorc -> Data[i] != ' ' && Sorc -> Data[i] != '\t')
        {
            End = i;
            break;
        }
    RetLen = End - Start + 1;
    String_AllocLength(Dest, RetLen);
    for(i = 0;i < RetLen;i ++)
        Dest -> Data[i] = Sorc -> Data[i + Start];
    Dest -> Data_Index = RetLen - 1;
}

void LTrim(String* Dest, String* Sorc)
{
    int Start, End, i, SorcLen, RetLen;
    SorcLen = Sorc -> Data_Index + 1;
    Start = 0;
    End = 0;
    for(i = SorcLen - 1;i >= 0;i --)
        if(Sorc -> Data[i] != ' ' && Sorc -> Data[i] != '\t')
        {
            End = i;
            break;
        }
    RetLen = End - Start + 1;
    String_AllocLength(Dest, RetLen);
    for(i = 0;i < RetLen;i ++)
        Dest -> Data[i] = Sorc -> Data[i + Start];
    Dest -> Data_Index = RetLen - 1;
}

void RTrim(String* Dest, String* Sorc)
{
    int Start, End, i, SorcLen, RetLen;
    SorcLen = Sorc -> Data_Index + 1;
    Start = 0;
    End = SorcLen - 1;
    for(i = 0;i < SorcLen;i ++)
        if(Sorc -> Data[i] != ' ' && Sorc -> Data[i] != '\t')
        {
            Start = i;
            break;
        }
    RetLen = End - Start + 1;
    String_AllocLength(Dest, RetLen);
    for(i = 0;i < RetLen;i ++)
        Dest -> Data[i] = Sorc -> Data[i + Start];
    Dest -> Data_Index = RetLen - 1;
}
*/

