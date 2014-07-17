#ifndef ENDIAN_SWITCH_H
#define ENDIAN_SWITCH_H

#include "../Core/OO.h"
#include <inttypes.h>

/* Endian_Switch_Inline.h */
RInline void Endian_Switch_Int16(short* val);
RInline void Endian_Switch_UInt16(unsigned short* val);
RInline void Endian_Switch_Int32(int* val);
RInline void Endian_Switch_UInt32(unsigned int* val);
RInline void Endian_Switch_Float(float* val);
RInline void Endian_Switch_Int64(int64_t* val);
RInline void Endian_Switch_UInt64(uint64_t* val);
RInline void Endian_Switch_Double(double* val);

/* Endian_Switch.c */
void Endian_Switch_Int16_Array(short* val, const int size);
void Endian_Switch_UInt16_Array(unsigned short* val, const int size);
void Endian_Switch_Int32_Array(int* val, const int size);
void Endian_Switch_UInt32_Array(unsigned int* val, const int size);
void Endian_Switch_Float_Array(float* val, const int size);
void Endian_Switch_Int64_Array(int64_t* val, const int size);
void Endian_Switch_UInt64_Array(uint64_t* val, const int size);
void Endian_Switch_Double_Array(double* val, const int size);

#include "Endian_Switch_Inline.h"

#endif // ENDIAN_SWITCH_H
