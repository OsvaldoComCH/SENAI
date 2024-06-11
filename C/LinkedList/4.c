#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
int LLCompare(const LList * L1, const LList * L2)
{
    if(L1->Size != L2->Size)
    {
        return 0;
    }
    LLNode * N1 = L1->Head, * N2 = L2->Head;
    for(int i = 0; i < L1->Size; ++i)
    {
        if(N1->Value != N2->Value)
        {
            return 0;
        }
        N1 = N1->Next;
        N2 = N2->Next;
    }
    return 1;
}

int main()
{
    LList L1, L2, L3;
    LListCreate(&L1);
    LListAdd(&L1, 1);
    LListAdd(&L1, 2);
    LListAdd(&L1, 3);
    LListAdd(&L1, 4);
    LListAdd(&L1, 5);
    LListAdd(&L1, 6);

    LListCreate(&L2);
    LListAdd(&L2, 1);
    LListAdd(&L2, 2);
    LListAdd(&L2, 3);
    LListAdd(&L2, 4);
    LListAdd(&L2, 5);
    LListAdd(&L2, 6);

    LListCreate(&L3);
    LListAdd(&L3, 6);
    LListAdd(&L3, 5);
    LListAdd(&L3, 4);
    LListAdd(&L3, 3);
    LListAdd(&L3, 2);
    LListAdd(&L3, 1);

    if(LLCompare(&L1, &L2))
    {
        printf("Iguais\n");
    }else
    {
        printf("Diferentes\n");
    }

    if(LLCompare(&L2, &L3))
    {
        printf("Iguais\n");
    }else
    {
        printf("Diferentes\n");
    }

    LListDestroy(&L1);
    LListDestroy(&L2);
    LListDestroy(&L3);
}