#include <stdio.h>
#include "LinkedStackQueue.h"

int main()
{
    LStack Stack;
    CreateLStack(&Stack);
    Push(&Stack, 1);
    Push(&Stack, 2);
    Push(&Stack, 3);
    Push(&Stack, 4);
    Push(&Stack, 5);
    printf("%i,", Pop(&Stack));
    printf("%i,", Pop(&Stack));
    printf("%i,", Pop(&Stack));
    printf("%i,", Pop(&Stack));
    printf("%i\n", Pop(&Stack));
    DeleteLStack(&Stack);
    LQueue Queue;
    CreateLQueue(&Queue);
    Enqueue(&Queue, 1);
    Enqueue(&Queue, 2);
    Enqueue(&Queue, 3);
    Enqueue(&Queue, 4);
    Enqueue(&Queue, 5);
    printf("%i,", Dequeue(&Queue));
    printf("%i,", Dequeue(&Queue));
    printf("%i,", Dequeue(&Queue));
    printf("%i,", Dequeue(&Queue));
    printf("%i\n", Dequeue(&Queue));
    DeleteLQueue(&Queue);
}