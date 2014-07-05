#include "UtfString.h" 

#include <string.h>
#include <memory.h>
#include "../Core/OO.h"

static const size_t Utf8_Skip_Data[256] = 
{
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 1, 1
};

#define _Utf8_NCopy_Core(Dest, Sorc, n)                                       \
    {                                                                         \
        size_t U8Size;                                                        \
        while(* Sorc && (U8Size = Utf8_Skip_Data[(UChar)(* Sorc)]) < n)     \
        {                                                                     \
            n -= U8Size;                                                      \
            memcpy(Dest, Sorc, U8Size);                                       \
            Dest += U8Size;                                                   \
            Sorc += U8Size;                                                   \
        }                                                                     \
        * Dest = '\0';                                                        \
    } (void)0

#define strcpy_utf8(Dest, Sorc) strcpy(Dest, Sorc)
#define strcat_utf8(Dest, Sorc) strcat(Dest, Sorc)

size_t strlen_utf8(const char* s)
{
    size_t Len;
    
    for (Len = 0; * s; ++Len)
        s += Utf8_Skip_Data[(UChar)(* s)];
    
    return Len;
}

size_t strnlen_utf8(const char* s, size_t n)
{
    size_t Len;
    const char* s_end = s + n;
    
    for (Len = 0; * s && s < s_end; ++Len)
        s += Utf8_Skip_Data[(UChar)(* s)];
    
    return Len;
}

char* strncpy_utf8(char* __restrict Dest, 
                   const char* __restrict Sorc, 
                   size_t n)
{
    char* Dest_Raw = Dest;
    
    RAssert(n);

    /* NOTE: currently we don't attempt to deal with invalid utf8 chars */
    _Utf8_NCopy_Core(Dest, Sorc, n);
    
    return (char *)Dest_Raw;
}

char* strncat_utf8(char* __restrict Dest, 
                   const char* __restrict Sorc, 
                   size_t n)
{
    while(* Dest && n > 0)
    {
        ++Dest;
        --n;
    }
    
    _Utf8_NCopy_Core(Dest, Sorc, n);

    return (char *)Dest;
}

char* next_char_safe_utf8(const char* p, const char* StrEnd)
{
    if(Likely(* p))
    {
        if(Likely(StrEnd))
            for(++p; p < StrEnd && (* p & 0xc0) == 0x80; ++p);
        else
            for(++p; (* p & 0xc0) == 0x80; ++p);
    }
    return (p == StrEnd) ? NULL : (char* )p;
}

char* next_char_utf8(const char* p)
{
    if(Likely(* p))
    {
        p += Utf8_Skip_Data[(UChar)(* p)];
    }
    return (char*)p;
}

char* prev_char_safe_utf8(const char* StrBegin, const char* p)
{
    for(--p; p >= StrBegin; --p)
    {
        if ((* p & 0xc0) != 0x80)
            return (char*)p;
    }
    
    return NULL;
}

char* prev_char_utf8(const char* p)
{
    while(1)
    {
        --p;
        if ((* p & 0xc0) != 0x80)
            return (char*)p;
    }
}