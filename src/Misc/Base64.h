#ifndef RUTIL2_BASE64_H
#define RUTIL2_BASE64_H

#include "../Core/OO.h"
#include "../Structure/String.h"

//Return the length after decoding (accurate).
int Base64_DecodeSize(int StringLen);

//Return the length after encoding (too large).
int Base64_EncodeSize(int DataLen);

//Return dest string length.
int Base64_Encode(String* Dest, void* SSrc, int SLen);

//SDest must be alloced. Use Base64_EncodeSize to get the length after decoding!
//Return accurate dest data length.
int Base64_Decode(void* SDest, String* Src);

#endif //RUTIL2_BASE64_H

