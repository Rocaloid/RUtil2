#ifndef RUTIL2_BASE64_H
#define RUTIL2_BASE64_H

int Base64_Encode(String *Dest, void *SSrc, int SLen); //Return dest string length.
int Base64_Decode(void *Dest, String *SSrc); //Return dest data length.

#endif //RUTIL2_BASE64_H