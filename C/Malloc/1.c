#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Tamanho: ");
    int s;
    scanf("%i", &s);
    int * A = (int *) malloc(s * sizeof(int));
    for(int i = 0; i < s; ++i)
    {
        printf("Numero [%i]: ", i+1);
        scanf("%i", &A[i]);
    }
    for(int i = 0; i < s; ++i)
    {
        printf("[%i]", A[i]);
    }
    free(A);
}