#include <stdio.h>
void Reverse(const char String[])
{
    static int i = 0;
    if(String[i] != '\0')
    {
        char c = String[i];
        ++i;
        Reverse(String);
        printf("%c", c);
    }
}

int main()
{
    char N[32];
    printf("Escreva: ");
    scanf("%s", &N);
    Reverse(N);
}