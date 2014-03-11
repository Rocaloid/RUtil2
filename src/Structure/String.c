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
/*
void String_Copy(String* Dest, const String* Src)
{
    ArrayType_Resize(char, Dest -> Data, Src -> Data_Index + 1);
    memcpy(Dest -> Data, Src -> Data, Src -> Data_Index + 1);
    Dest -> Data_Index = Src -> Data_Index;
}

int String_GetLength(String* Src)
{
    return Src -> Data_Index + 1;
}

void String_AllocLength(String* Dest, int Length)
{
    ArrayType_Resize(char, Dest -> Data, Length);
}

char String_GetChar(String* Dest, int Index)
{
    return Dest -> Data[Index];
}

void String_SetChar(String* Dest, int Index, char Data)
{
    Dest -> Data[Index] = Data;
}

void String_Join(String* Dest, const String* Src)
{
    ArrayType_Resize(char, Dest -> Data, Dest -> Data_Index + Src -> Data_Index + 2 + Dest -> Data_Index / 10);
    memcpy(Dest -> Data + Dest -> Data_Index + 1, Src -> Data, Src -> Data_Index + 1);
    Dest -> Data_Index += Src -> Data_Index + 1;
}

void String_JoinChars(String* Dest, const char* Src)
{
    int Len = strlen(Src);
    ArrayType_Resize(char, Dest -> Data, Dest -> Data_Index + Len + 1 + Dest -> Data_Index / 10);
    memcpy(Dest -> Data + Dest -> Data_Index + 1, Src, Len);
    Dest -> Data_Index += Len;
}

int String_Equal(const String* Str1, const String* Str2)
{
    return (Str1 -> Data_Index == Str2 -> Data_Index) &&
           (! strncmp(Str1 -> Data, Str2 -> Data, Str1 -> Data_Index + 1));
}

int String_EqualChars(const String* Str1, const char* Str2)
{
    if(strlen(Str2) == (size_t)Str1 -> Data_Index + 1)
        return ! strncmp(Str1 -> Data, Str2, Str1 -> Data_Index + 1);
    return 0;
}

//------------------------------------------------------------

void Mid(String* Dest, const String* Src, int From, int Count)
{
    int i;
    if(Count + From > Src -> Data_Index)
        Count = Src -> Data_Index - From + 1;
    if(Count < 0)
        Count = 0;
    String_AllocLength(Dest, Count);
    for(i = 0;i < Count;i ++)
        Dest -> Data[i] = Src -> Data[From + i];
    Dest -> Data_Index = Count - 1;
}

void MidFrom(String* Dest, const String* Src, int From)
{
    int i;
    int Count = Src -> Data_Index - From + 1;
    if(Count < 0)
        Count = 0;
    String_AllocLength(Dest, Count);
    for(i = 0;i < Count;i ++)
        Dest -> Data[i] = Src -> Data[From + i];
    Dest -> Data_Index = Count - 1;
}

void Right(String* Dest, const String* Src, int Count)
{
    int i;
    if(Src -> Data_Index - Count < - 1)
        Count = Src -> Data_Index + 1;
    int From = Src -> Data_Index + 1 - Count;
    if(Count < 0)
        Count = 0;
    String_AllocLength(Dest, Count);
    for(i = 0;i < Count;i ++)
        Dest -> Data[i] = Src -> Data[From + i];
    Dest -> Data_Index = Count - 1;
}

void Left(String* Dest, const String* Src, int Count)
{
    int i;
    if(Count > Src -> Data_Index + 1)
        Count = Src -> Data_Index + 1;
    if(Count < 0)
        Count = 0;
    String_AllocLength(Dest, Count);
    for(i = 0;i < Count;i ++)
        Dest -> Data[i] = Src -> Data[i];
    Dest -> Data_Index = Count - 1;
}

void UpperCase(String* Dest, const String* Src)
{
    int i;
    int Len = Src -> Data_Index + 1;
    String_AllocLength(Dest, Len);
    for(i = 0;i < Len;i ++)
        if(Src -> Data[i] >= 'a' && Src -> Data[i] <= 'z')
            Dest -> Data[i] = Src -> Data[i] + ('A' - 'a');
        else
            Dest -> Data[i] = Src -> Data[i];
    Dest -> Data_Index = Len - 1;
}

void LowerCase(String* Dest, const String* Src)
{
    int i;
    int Len = Src -> Data_Index + 1;
    String_AllocLength(Dest, Len);
    for(i = 0;i < Len;i ++)
        if(Src -> Data[i] >= 'A' && Src -> Data[i] <= 'Z')
            Dest -> Data[i] = Src -> Data[i] + ('a' - 'A');
        else
            Dest -> Data[i] = Src -> Data[i];
    Dest -> Data_Index = Len - 1;
}

int InStrFrom(String* Whole, String* Part, int From)
{
    int i, j;
    int End = Whole -> Data_Index - Part -> Data_Index;
    int PartLen = Part -> Data_Index + 1;

    ArrayType_Push(char, Whole -> Data, 0);
    Whole -> Data_Index --;
    ArrayType_Push(char, Part -> Data, 0);
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

    ArrayType_Push(char, Whole -> Data, 0);
    Whole -> Data_Index --;
    ArrayType_Push(char, Part -> Data, 0);
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

void Trim(String* Dest, const String* Src)
{
    int Start, End, i, SrcLen, RetLen;
    SrcLen = Src -> Data_Index + 1;
    Start = 0;
    End = 0;
    for(i = 0;i < SrcLen;i ++)
        if(Src -> Data[i] != ' ' && Src -> Data[i] != '\t')
        {
            Start = i;
            break;
        }
    for(i = SrcLen - 1;i >= 0;i --)
        if(Src -> Data[i] != ' ' && Src -> Data[i] != '\t')
        {
            End = i;
            break;
        }
    RetLen = End - Start + 1;
    String_AllocLength(Dest, RetLen);
    for(i = 0;i < RetLen;i ++)
        Dest -> Data[i] = Src -> Data[i + Start];
    Dest -> Data_Index = RetLen - 1;
}

void LTrim(String* Dest, const String* Src)
{
    int Start, End, i, SrcLen, RetLen;
    SrcLen = Src -> Data_Index + 1;
    Start = 0;
    End = 0;
    for(i = SrcLen - 1;i >= 0;i --)
        if(Src -> Data[i] != ' ' && Src -> Data[i] != '\t')
        {
            End = i;
            break;
        }
    RetLen = End - Start + 1;
    String_AllocLength(Dest, RetLen);
    for(i = 0;i < RetLen;i ++)
        Dest -> Data[i] = Src -> Data[i + Start];
    Dest -> Data_Index = RetLen - 1;
}

void RTrim(String* Dest, const String* Src)
{
    int Start, End, i, SrcLen, RetLen;
    SrcLen = Src -> Data_Index + 1;
    Start = 0;
    End = SrcLen - 1;
    for(i = 0;i < SrcLen;i ++)
        if(Src -> Data[i] != ' ' && Src -> Data[i] != '\t')
        {
            Start = i;
            break;
        }
    RetLen = End - Start + 1;
    String_AllocLength(Dest, RetLen);
    for(i = 0;i < RetLen;i ++)
        Dest -> Data[i] = Src -> Data[i + Start];
    Dest -> Data_Index = RetLen - 1;
}
*/

