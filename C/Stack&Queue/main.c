#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Stack&Queue.h"

int Fila(QS * Queue)
{
    int id = 0;
    int Time = 0; //0 = 8:00, 1 = 8:05, 108 = 17:00, 168 = 22:00
    while(Time++ < 168)
    {
        if(!(rand() % (2 + (Time < 108) * 3)))
        {
            Enqueue(Queue, ++id);
            printf("Pessoa %i entrou: %i:%i\n", id, 8 + (Time / 12), 5*(Time % 12));
        }
        if(!(rand() % 10) && QSSize(Queue) > 0)
        {
            printf("Pessoa %i saiu: %i:%i\n", Dequeue(Queue), 8 + (Time / 12), 5*(Time % 12));
            if(QSSize(Queue) <= 0)
            {
                printf("Acabou a fila.");
                return 0;
            }
        }
        for(int i = 0; i < QSSize(Queue); ++i)
        {
            if(!(rand() % 100))
            {
                printf("Pessoa %i desistiu\n", Remove(Queue, i));
                if(QSSize(Queue) <= 0)
                {
                    printf("Acabou a fila.");
                    return 0;
                }
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    QUEUE Queue;
    CreateQueue(&Queue, 100);
    Fila(&Queue);
    DestroyQueue(&Queue);
}