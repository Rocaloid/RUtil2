/* only include from header */
#ifndef ENDIAN_SWITCH_H
    #error "this file isnt to be directly included"
#endif

#ifndef ENDIAN_SWITCH_INLINE_H
#define ENDIAN_SWITCH_INLINE_H

/* *** 16 *** */
RInline void Endian_Switch_Int16(short* val)
{
    Endian_Switch_UInt16((unsigned short*)val);
}
RInline void Endian_Switch_UInt16(unsigned short* val)
{
    unsigned short tval = (* val);
    (* val) = (tval >> 8) |
           (tval << 8);
}


/* *** 32 *** */
RInline void Endian_Switch_Int32(int* val)
{
    Endian_Switch_UInt32((unsigned int*)val);
}
RInline void Endian_Switch_UInt32(unsigned int* val)
{
    unsigned int tval = (* val);
    (* val) = ((tval >> 24))             |
           ((tval << 8) & 0x00ff0000) |
           ((tval >> 8) & 0x0000ff00) |
           ((tval << 24));
}
RInline void Endian_Switch_Float(float* val)
{
    Endian_Switch_UInt32((unsigned int*)val);
}


/* *** 64 *** */
RInline void Endian_Switch_Int64(int64_t* val)
{
    Endian_Switch_UInt64((uint64_t*)val);
}
RInline void Endian_Switch_UInt64(uint64_t* val)
{
    uint64_t tval = (* val);
    (* val) = ((tval >> 56)) |
           ((tval << 40) & 0x00ff000000000000ll) |
           ((tval << 24) & 0x0000ff0000000000ll) |
           ((tval <<  8) & 0x000000ff00000000ll) |
           ((tval >>  8) & 0x00000000ff000000ll) |
           ((tval >> 24) & 0x0000000000ff0000ll) |
           ((tval >> 40) & 0x000000000000ff00ll) |
           ((tval << 56));
}
RInline void Endian_Switch_Double(double* val)
{
    Endian_Switch_UInt64((uint64_t*)val);
}

#endif // ENDIAN_SWITCH_INLINE_H
