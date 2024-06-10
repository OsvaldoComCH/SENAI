#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{
    int A[6] = {1,2,3,4,5,6};
    LList L;
    LListCreate(&L);
    for(int i = 0; i < 6; ++i)
    {
        LListAdd(&L, A[i]);
    }
    for(int i = 0; i < 6; ++i)
    {
        printf("%i, ", LListGet(&L, i));
    }
    LListDestroy(&L);
}