#include <stdio.h>
#include <stdlib.h>
#include "1.h"
int * GetArray(int Size)
{
    int * p = malloc(Size*sizeof(int));
    for(int i = 0; i < Size; ++i)
    {
        p[i] = i;
    }
    return p;
}
int main()
{
    int x;
    printf("Tamanho: ");
    scanf("%i", &x);
    int * Ptr = GetArray(x);
    PrintArray(Ptr, x);
    free(Ptr);
}