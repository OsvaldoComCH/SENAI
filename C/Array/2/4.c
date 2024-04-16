#include <stdio.h>
int main()
{
    int A[2][3][2];
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            printf("Matriz 1 [%i][%i]: ", i, j);
            scanf("%i", &A[0][i][j]);
        }
    }
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            printf("Matriz 2 [%i][%i]: ", i, j);
            scanf("%i", &A[1][i][j]);
        }
    }
    printf("Matriz 1:\n");
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            printf("[%i]", A[0][i][j]);
        }
        printf("\n");
    }
    printf("Matriz 2:\n");
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            printf("[%i]", A[1][i][j]);
        }
        printf("\n");
    }
    printf("Soma:\n");
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            printf("[%i]", A[0][i][j] + A[1][i][j]);
        }
        printf("\n");
    }
}