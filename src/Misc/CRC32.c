#include <unistd.h>
#include "CRC32.h"
#ifdef __BIG_ENDIAN__
    #include "CRC32_TABLE_BE.h"
    #define A(x) ((x) >> 24)
    #define B(x) (((x) >> 16) & 0xFF)
    #define C(x) (((x) >> 8) & 0xFF)
    #define D(x) ((x) & 0xFF)

    #define S8(x) ((x) << 8)
    #define S32(x) ((x) << 32)

#else
    #include "CRC32_TABLE_LE.h"
    #define A(x) ((x) & 0xFF)
    #define B(x) (((x) >> 8) & 0xFF)
    #define C(x) (((x) >> 16) & 0xFF)
    #define D(x) ((x) >> 24)

    #define S8(x) ((x) >> 8)
    #define S32(x) ((x) >> 32)
#endif
#include "../Core/OO.h"


UInt CRC32Sum(const void* Buffer_P, size_t Size, UInt CRC)
{
    const UChar* Buffer = Buffer_P;
    
    CRC = ~CRC;

#ifdef __BIG_ENDIAN__
    CRC = Endian_Switch_Uint32(CRC);
#endif

    if (Size > 8) {
        // Fix the alignment, if needed. The if statement above
        // ensures that this won't read past the end of Buffer[].
        while ((uintptr_t)(Buffer) & 7) {
            CRC = CRC32_TABLE[0][*Buffer ++ ^ A(CRC)] ^ S8(CRC);
            --Size;
        }

        // Calculate the position where to stop.
        const UChar* const limit = Buffer + (Size & ~(size_t)(7));

        // Calculate how many bytes must be calculated separately
        // before returning the result.
        Size &= (size_t)(7);

        // Calculate the CRC32 using the slice-by-eight algorithm.
        while (Buffer < limit) {
            CRC ^=*(const UInt*)(Buffer);
            Buffer += 4;

            CRC = CRC32_TABLE[7][A(CRC)]
                ^ CRC32_TABLE[6][B(CRC)]
                ^ CRC32_TABLE[5][C(CRC)]
                ^ CRC32_TABLE[4][D(CRC)];

            const UInt tmp =*(const UInt*)(Buffer);
            Buffer += 4;

            // At least with some compilers, it is critical for
            // performance, that the CRC variable is XORed
            // between the two table-lookup pairs.
            CRC = CRC32_TABLE[3][A(tmp)]
                ^ CRC32_TABLE[2][B(tmp)]
                ^ CRC
                ^ CRC32_TABLE[1][C(tmp)]
                ^ CRC32_TABLE[0][D(tmp)];
        }
    }

    while ((Size --) != 0)
        CRC = CRC32_TABLE[0][*(Buffer ++) ^ A(CRC)] ^ S8(CRC);

#ifdef __BIG_ENDIAN__
    CRC = Endian_Switch_UInt32(CRC);
#endif

    return ~CRC;
}
