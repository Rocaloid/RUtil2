#ifndef RUTIL2_BASE64_H
#define RUTIL2_BASE64_H

#include "../Core/OO.h"
#include "../Structure/String.h"

//Return dest string length.
int Base64_Encode(String* Dest, void* SSrc, int SLen);

//Return dest data length.
int Base64_Decode(void* Dest, String* SSrc);

#endif //RUTIL2_BASE64_H

