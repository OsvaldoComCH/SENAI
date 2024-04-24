#include <stdio.h>
#include <stdlib.h>
int main()
{
    int Size;
    int * A[3];
    printf("Itens: ");
    scanf("%i", &Size);
    A[0] = malloc(Size*sizeof(int));
    A[1] = malloc(Size*sizeof(int));
    A[2] = malloc(Size*sizeof(int));
    for(int i = 0; i < Size; ++i)
    {
        printf("Valor [0][%i]: ", i);
        scanf("%i", &A[0][i]);
    }
    for(int i = 0; i < Size; ++i)
    {
        printf("Valor [1][%i]: ", i);
        scanf("%i", &A[1][i]);
        A[2][i] = A[1][i] + A[0][i];
    }
    for(int i = 0; i < Size; ++i)
    {
        printf("[%i]", A[0][i]);
    }
    printf("\n");
    for(int i = 0; i < Size; ++i)
    {
        printf("[%i]", A[1][i]);
    }
    printf("\n");
    for(int i = 0; i < Size; ++i)
    {
        printf("[%i]", A[2][i]);
    }
}