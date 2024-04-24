#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char Text[3][3][50];
    for(int i = 0; i < 3; ++i)
    {
        printf("Texto 1 Linha %i: ", i+1);
        scanf(" %s", &Text[0][i]);
    }
    for(int i = 0; i < 3; ++i)
    {
        printf("Texto 2 Linha %i: ", i+1);
        scanf(" %s", &Text[1][i]);
    }
    for(int i = 0; i < 3; ++i)
    {
        if(strcmp(Text[0][i], Text[1][i]))
        {
            strcpy(Text[2][i], "DIFERENTE");
        }else
        {
            strcpy(Text[2][i], "IGUAL");
        }
        printf("%s\n", Text[2][i]);
    }
}