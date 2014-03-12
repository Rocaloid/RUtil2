#include <stdio.h>
#include "Structure/String.h"
#include "Misc/Convert.h"
#include "IO/File.h"
#include "IO/WaveFile.h"

int main(void)
{
    /* Generic File IO
    String Path, tmp;
    RNew(String, & Path, & tmp);
    String_SetChars(& Path, "/tmp/a.txt");
    
    File TestFile, WriteFile;
    RNew(File, & TestFile, & WriteFile);
    int Status = File_Open(& TestFile, & Path, READONLY);
    printf("%d\n", Status);
    
    String_SetChars(& Path, "/tmp/b.txt");
    Status = File_Open(& WriteFile, & Path, WRITEONLY);
    printf("%d\n", Status);
    
    File_ReadLine(& TestFile, & tmp);
    printf("%s\n", String_GetChars(& tmp));
    
    int i;
    double a;
    for(i = 0; i < 100; i ++)
    {
        a = File_Read_Double(& TestFile);
        printf("%lf\n", a);
        File_Write_Double(& WriteFile, a / 2);
    }
    
    File_Write_Buffer(& WriteFile, Path.Data, 3);
    
    File_Close(& TestFile);
    File_Flush(& WriteFile);
    RDelete(& Path, & TestFile, & tmp, & WriteFile);
    */
    return 0;
}

