#ifndef RUTIL2_BASE64_H
#define RUTIL2_BASE64_H

#include "../Core/OO.h"
#include "../Structure/String.h"

/* 给定Base64字符串长度计算解码后数据大小，返回值可能偏大 */
// Return the length after decoding (est.).
int Base64_DecodeSize(int StrSize);

/* 给定数据长度计算遍码后Base64大小 */
// Return the length after encoding.
int Base64_EncodeSize(int DataSize);

/* 编码，返回字符串长度 */
// Return accurate dest string length.
int Base64_Encode(String* Dest, void* Sorc, int Size);

/* 解码，返回精确的数据长度 */
// Dest must be alloced. Use Base64_DecodeSize to get the length (est.)!
// Return accurate dest data length.
int Base64_Decode(void* Dest, String* Sorc);

/* 将3字节Base64编码后字符解码到一个Int16中 */
// Decode a encoded 12bit integer to a int16.
short Base64_Decode_Int12(char* Sorc);

#endif //RUTIL2_BASE64_H

