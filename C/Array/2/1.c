#include <stdio.h>
int main()
{
    int A[4][4];
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            printf("Numero [%i][%i]: ", i, j);
            scanf("%i", &A[i][j]);
        }
    }
    int soma;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            soma += A[i][j];
        }
    }
    printf("Soma: %i", soma);
}