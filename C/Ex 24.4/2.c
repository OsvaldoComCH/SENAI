#include <stdio.h>
#include <stdlib.h>
#include "1.h"
int main()
{
    int M[4][4];
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            printf("Valor [%i][%i]: ", i, j);
            scanf("%i", &M[i][j]);
        }
    }
    int * A = malloc(sizeof(M));
    int x = 0;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            A[x++] = M[i][j];
        }
    }
    PrintArray(A, 16);
}