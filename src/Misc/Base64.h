#ifndef RUTIL2_BASE64_H
#define RUTIL2_BASE64_H

int Base64_Encode(String *Dest, char *Src, int SLen); //Return dest string length.
int Base64_Decode(char *Dest, String *Src); //Return dest data length.

#endif //RUTIL2_BASE64_H