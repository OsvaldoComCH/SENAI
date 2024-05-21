#ifndef LINKED_STACK_QUEUE
#define LINKED_STACK_QUEUE
#include <stdlib.h>

typedef struct SQ
{
    int Value;
    struct SQ * Next;
} LStack, LQueue;

void CreateLStack(LStack * Stack)
{
    Stack = (LStack *) malloc(sizeof(LStack));
    Stack->Next = NULL;
}

void Push(LStack * Stack, int Value)
{
    if(Stack->Next)
    {
        LStack * S = Stack;
        Stack = (LStack *) malloc(sizeof(LStack));
        Stack->Next = S;
    }
    Stack->Value = Value;
}

int Pop(LStack * Stack)
{
    LStack * S = Stack;
    int Value = S->Value;
    Stack = Stack->Next;
    free(S);
    return Value;
}

void DeleteLStack(LStack * Stack)
{
    while(Stack)
    {
        LStack * S = Stack->Next;
        free(Stack);
        Stack = S;
    }
}

void CreateLQueue(LQueue * Queue)
{
    Queue = (LQueue *) malloc(sizeof(LQueue));
    Queue->Next = NULL;
}

void Enqueue(LQueue * Queue, int Value)
{
    if(Queue->Next)
    {
        LQueue * S = Queue;
        Queue = (LQueue *) malloc(sizeof(LQueue));
        Queue->Next = S;
    }
    Queue->Value = Value;
}

int Dequeue(LQueue * Queue)
{
    LQueue * Q = Queue, * L = Queue;
    while(Q->Next)
    {
        L = Q;
        Q = Q->Next;
    }
    L->Next = NULL;
    int Value = Q->Value;
    free(Q);
    return Value;
}

void DeleteLQueue(LQueue * Queue)
{
    while(Queue)
    {
        LQueue * S = Queue->Next;
        free(Queue);
        Queue = S;
    }
}
#endif