#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{
    LList L;
    LListCreate(&L);
    LListAdd(&L, 1);
    LListAdd(&L, 2);
    LListAdd(&L, 3);
    LListAdd(&L, 4);
    LListAdd(&L, 5);
    LListAdd(&L, 6);
    int * A = malloc(L.Size*sizeof(int));
    for(int i = 0; i < L.Size; ++i)
    {
        A[i] = LListGet(&L, i);
    }
    for(int i = 0; i < L.Size; ++i)
    {
        printf("%i, ", A[i]);
    }
    LListDestroy(&L);
}