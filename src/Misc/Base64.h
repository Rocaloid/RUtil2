#ifndef RUTIL2_BASE64_H
#define RUTIL2_BASE64_H

#include "../Core/OO.h"
#include "../Structure/String.h"

//Return the length after decoding (est.).
int Base64_DecodeSize(int StrSize);

//Return the length after encoding.
int Base64_EncodeSize(int DataSize);

//Return accurate dest string length.
int Base64_Encode(String* Dest, void* Sorc, int Size);

//Dest must be alloced. Use Base64_EncodeSize to get the length after decoding!
//Return accurate dest data length.
int Base64_Decode(void* Dest, String* Sorc);

#endif //RUTIL2_BASE64_H

