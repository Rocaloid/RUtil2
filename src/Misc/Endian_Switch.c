#include "Endian_Switch.h"

void Endian_Switch_Int16_Array(short* val, const int size)
{
    if (size > 0)
    {
        int i = size;
        val = val + (size - 1);
        while(-- i)
        {
            Endian_Switch_Int16(val --);
        }
    }
}

void Endian_Switch_UInt16_Array(unsigned short* val, const int size)
{
    if (size > 0)
    {
        int i = size;
        val = val + (size - 1);
        while(-- i)
        {
            Endian_Switch_UInt16(val --);
        }
    }
}

void Endian_Switch_Int32_Array(int* val, const int size)
{
    if (size > 0)
    {
        int i = size;
        val = val + (size - 1);
        while(-- i)
        {
            Endian_Switch_Int32(val --);
        }
    }
}

void Endian_Switch_UInt32_Array(unsigned int* val, const int size)
{
    if (size > 0)
    {
        int i = size;
        val = val + (size - 1);
        while(-- i)
        {
            Endian_Switch_UInt32(val --);
        }
    }
}

void Endian_Switch_Float_Array(float* val, const int size)
{
    if (size > 0)
    {
        int i = size;
        val = val + (size - 1);
        while(-- i)
        {
            Endian_Switch_Float(val --);
        }
    }
}

void Endian_Switch_Int64_Array(int64_t* val, const int size)
{
    if (size > 0)
    {
        int i = size;
        val = val + (size - 1);
        while(-- i)
        {
            Endian_Switch_Int64(val --);
        }
    }
}

void Endian_Switch_UInt64_Array(uint64_t* val, const int size)
{
    if (size > 0)
    {
        int i = size;
        val = val + (size - 1);
        while(-- i)
        {
            Endian_Switch_UInt64(val --);
        }
    }
}


void Endian_Switch_Double_Array(double* val, const int size)
{
    if (size > 0)
    {
        int i = size;
        val = val + (size - 1);
        while(-- i)
        {
            Endian_Switch_Double(val --);
        }
    }
}