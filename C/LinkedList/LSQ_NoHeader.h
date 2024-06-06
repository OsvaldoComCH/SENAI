#ifndef LINKED_STACK_QUEUE
#define LINKED_STACK_QUEUE
#include <stdlib.h>
#include <stdio.h>

typedef struct SQNode
{
    int Value;
    struct SQNode * Next, * Prev;
} LStack, LQueue, SQNode;

void CreateLStack(LStack ** Stack)
{
    (*Stack) = NULL;
}

void Push(LStack ** Stack, int Value)
{
    SQNode * S = (SQNode *) malloc(sizeof(SQNode));
    S->Prev = NULL;
    S->Value = Value;
    S->Next = (*Stack);
    if((*Stack))
    {
        (*Stack)->Prev = S;
    }
    (*Stack) = S;
}

int Pop(LStack ** Stack)
{
    int Value = (*Stack)->Value;
    if((*Stack)->Next == NULL)
    {
        free((*Stack));
        (*Stack) = NULL;
    }else
    {
        (*Stack) = (*Stack)->Next;
        free((*Stack)->Prev);
        (*Stack)->Prev = NULL;
    }
    return Value;
}

void DeleteLStack(LStack ** Stack)
{
    while((*Stack))
    {
        Pop(Stack);
    }
}

void CreateLQueue(LQueue ** Queue)
{
    (*Queue) = NULL;
}

void Enqueue(LQueue ** Queue, int Value)
{
    SQNode * Q = (SQNode *) malloc(sizeof(SQNode));
    Q->Prev = NULL;
    Q->Value = Value;
    Q->Next = (*Queue);
    if((*Queue))
    {
        (*Queue)->Prev = Q;
    }
    (*Queue) = Q;
}

int Dequeue(LQueue ** Queue)
{
    LQueue * Q = (*Queue), * QPrev = NULL;
    while(Q->Next)
    {
        QPrev = Q;
        Q = Q->Next;
    }
    int Value = Q->Value;
    if(QPrev == NULL)
    {
        free(Q);
        (*Queue) = NULL;
    }else
    {
        Q = Q->Prev;
        free(Q->Next);
        Q->Next = NULL;
    }
    return Value;
}

void DeleteLQueue(LQueue ** Queue)
{
    while((*Queue))
    {
        Pop(Queue);
    }
}

#endif