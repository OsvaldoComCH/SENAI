#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct QUEUE
{
    int * Data;
    int * Pointer;
} QUEUE;

void CreateQueue(QUEUE * Queue, int Length)
{
    Queue->Data = (int *) malloc(Length*sizeof(int));
    Queue->Pointer = Queue->Data;
}

void Enqueue(QUEUE * Queue, int Item)
{
    *Queue->Pointer = Item;
    Queue->Pointer = Queue->Pointer + 4;

}

int Dequeue(QUEUE * Queue)
{
    Queue->Pointer -= 4;
    int Value = *Queue->Data;
    for(int * i = Queue->Data; i <= Queue->Pointer; i+=4)
    {
        *i = *(i+4);
    }
    return Value;
}

void DestroyQueue(QUEUE * Queue)
{
    free(Queue->Data);
    Queue->Pointer = NULL;
}

#endif