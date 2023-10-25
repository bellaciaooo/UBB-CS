#include <stdio.h>

extern void transformare(char*, char*);

/*void transformareC(char* s,char* rezultat)
{
    for (int i = 0; i<8; i++)
    {
        int cifHex = 0;
        cifHex *= 2;
        cifHex += s[i*4]-'0';
        cifHex *= 2;
        cifHex += s[i*4+1]-'0';
        cifHex *= 2;
        cifHex += s[i*4+2]-'0';
        cifHex *= 2;
        cifHex += s[i*4+3]-'0';
        rezultat[i] = cifreHexa[cifHex];
    }
    rezultat[8] = 0;
}*/

int main()
{  
    char s[33], rezultat[9];
    scanf("%s",s);
    transformare(s,rezultat);
    printf("%s",rezultat);
    return 0;
}