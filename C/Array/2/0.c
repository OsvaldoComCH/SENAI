#include <stdio.h>
int main()
{
    int A[2][2];
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            printf("Numero [%i][%i]: ", i, j);
            scanf("%i", &A[i][j]);
        }
    }
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            printf("[%i]", A[i][j]);
        }
        printf("\n");
    }
}