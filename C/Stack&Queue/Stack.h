#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct STACK
{
    int * Data;
    int * Pointer;
} STACK;

void CreateStack(STACK * Stack, int Length)
{
    Stack->Data = (int *) malloc(Length*sizeof(int));
    Stack->Pointer = Stack->Data;
}

void StackPush(STACK * Stack, int Item)
{
    *Stack->Pointer = Item;
    Stack->Pointer += 4;
}

int StackPop(STACK * Stack)
{
    Stack->Pointer -= 4;
    return *Stack->Pointer;
}

int StackPeek(STACK * Stack)
{
    return *(Stack->Pointer-1);
}

void DestroyStack(STACK * Stack)
{
    free(Stack->Data);
    Stack->Pointer = NULL;
}

#endif