#include <stdio.h>
void Single(const char String[])
{
    static int i = 0;
    if(String[i] != '\0')
    {
        char c = String[i];
        ++i;
        Single(String);
        printf("%c", c);
    }
}

int main()
{
    char N[32];
    printf("Escreva: ");
    scanf("%s", &N);
    Single(N);
}