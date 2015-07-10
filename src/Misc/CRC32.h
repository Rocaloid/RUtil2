#ifndef RUTIL2_CRC32_H
#define RUTIL2_CRC32_H

#include <unistd.h>
#include "../Core/OO.h"

/* 计算CRC32，可给Crc参数赋值实现分块计算 */
UInt CRC32Sum(const void* Buffer_P, size_t Size, UInt Crc);

#endif //RUTIL2_CRC32_H
