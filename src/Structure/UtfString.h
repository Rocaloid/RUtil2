#ifndef RUTIL2_UTFSTRING_H
#define RUTIL2_UTFSTRING_H

#include <unistd.h>
#include "../Core/OO.h"

size_t strlen_utf8(const char* s);
size_t strnlen_utf8(const char* s, size_t n);

char* strncpy_utf8(char* __restrict Dest, 
                   const char* __restrict Sorc, 
                   size_t n);

char* strncat_utf8(char* __restrict Dest, 
                   const char* __restrict Sorc, 
                   size_t n);

char* next_char_safe_utf8(const char* p, const char* StrEnd);
char* next_char_utf8(const char* p);
char* prev_char_safe_utf8(const char* StrBegin, const char* p);
char* prev_char_utf8(const char* p);

#endif //RUTIL2_UTFSTRING_H