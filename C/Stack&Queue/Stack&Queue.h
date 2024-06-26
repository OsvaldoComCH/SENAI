#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct QS
{
    int * Data;
    int * Pointer;
} QUEUE, STACK, QS;

void CreateQueue(QUEUE * Queue, int Length)
{
    Queue->Data = (int *) malloc(Length*sizeof(int));
    Queue->Pointer = Queue->Data;
}

void Enqueue(QUEUE * Queue, int Item)
{
    *Queue->Pointer = Item;
    ++Queue->Pointer;
}

int Remove(QUEUE * Queue, int N)
{
    int Value = Queue->Data[N];
    for(int * i = &Queue->Data[N]; i < Queue->Pointer; ++i)
    {
        *i = *(i+1);
    }
    --Queue->Pointer;
    return Value;
}

int Dequeue(QUEUE * Queue)
{
    --Queue->Pointer;
    int Value = *Queue->Data;
    for(int * i = Queue->Data; i <= Queue->Pointer; ++i)
    {
        *i = *(i+1);
    }
    return Value;
}

void DestroyQueue(QUEUE * Queue)
{
    free(Queue->Data);
    Queue->Pointer = NULL;
}

int QSSize(QS * qs)
{
    return qs->Pointer - qs->Data;
}

void CreateStack(STACK * Stack, int Length)
{
    Stack->Data = (int *) malloc(Length*sizeof(int));
    Stack->Pointer = Stack->Data;
}

void StackPush(STACK * Stack, int Item)
{
    *Stack->Pointer = Item;
    ++Stack->Pointer;
}

int StackPop(STACK * Stack)
{
    --Stack->Pointer;
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