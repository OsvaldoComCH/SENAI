#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

int main()
{
    STACK S;
    QUEUE Q;
    CreateStack(&S, 10);
    StackPush(&S, 1);
    StackPush(&S, 2);
    StackPush(&S, 3);
    StackPush(&S, 4);
    StackPush(&S, 5);
    for(int i = 0; i < 5; ++i)
    {
        printf("%i,", StackPop(&S));
    }
    /*printf("%i, %i, %i, %i, %i", StackPop(&S), StackPop(&S),
    StackPop(&S), StackPop(&S), StackPop(&S));*/
    DestroyStack(&S);

    CreateQueue(&Q, 10);
    Enqueue(&Q, 1);
    Enqueue(&Q, 2);
    Enqueue(&Q, 3);
    Enqueue(&Q, 4);
    Enqueue(&Q, 5);
    for(int i = 0; i < 5; ++i)
    {
        printf("%i,", Dequeue(&Q));
    }
    /*printf("%i, %i, %i, %i, %i", Dequeue(&Q), Dequeue(&Q),
    Dequeue(&Q), Dequeue(&Q), Dequeue(&Q));*/
    DestroyQueue(&Q);
}