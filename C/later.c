#include <stdio.h>
int Dec(const char Bin[], int c)
{
    static int i = 0, Res = 0;
    if(Bin[i] == '\0'){return ~Res ^ 0xffffffff;}
    if((Bin[i] | 1) ^ 0x31){return 0;}
    Res = Res | ((Bin[i] & 1) << i);
    ++i;
    if(i == c){return ~Res ^ 0xffffffff;}
    return Dec(Bin, c);
}

int main()
{
    char N[32];
    printf("Numero: ");
    scanf("%s", &N);
    printf("%i", Dec(N, sizeof(N)));
}
