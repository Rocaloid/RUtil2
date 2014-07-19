#define _Endian_Switch _C(Endian_Switch, _, _T1)

#if _T1_DataLen == 16
    #define RVal (* ((UInt16 *)(Val)))
#elif _T1_DataLen == 32
    #define RVal (* ((UInt32 *)(Val)))
#elif _T1_DataLen == 64
    #define RVal (* ((UInt64 *)(Val)))
#endif

RTFunc(RInline void, Endian_Switch, _T1* val)
{
    #if _T1_DataLen == 16
        UInt16 tval = (UInt16)RVal;
        RVal = (tval >> 8) |
               (tval << 8);
    #elif _T1_DataLen == 32
        UInt32 tval = (UInt32)RVal;
        RVal = ((tval >> 24))             |
               ((tval << 8) & 0x00ff0000) |
               ((tval >> 8) & 0x0000ff00) |
               ((tval << 24));
    #elif _T1_DataLen == 64
        UInt64 tval = (UInt64)RVal;
        RVal = ((tval >> 56))                        |
               ((tval << 40) & 0x00ff000000000000ll) |
               ((tval << 24) & 0x0000ff0000000000ll) |
               ((tval <<  8) & 0x000000ff00000000ll) |
               ((tval >>  8) & 0x00000000ff000000ll) |
               ((tval >> 24) & 0x0000000000ff0000ll) |
               ((tval >> 40) & 0x000000000000ff00ll) |
               ((tval << 56));
    #endif
}

RTFunc(RInline void, Endian_Switch_Array, _T1* val, int Size)
{
    if (Size > 0)
    {
        int i = Size;
        val = val + (Size - 1);
        while(-- i)
            _Endian_Switch(val --);
    }
}