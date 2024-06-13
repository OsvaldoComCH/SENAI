#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

int main()
{
    int * A, Size, x;
    printf("Tamanho: ");
    scanf("%i", &Size);

    A = malloc(Size*sizeof(int));
    printf("0-Preencher Manual\n1-Preencher Aleatorio\n");
    scanf("%i", &x);
    if(x)
    {
        srand(time(NULL));
        for(int i = 0; i < Size; ++i)
        {
            A[i] = rand() % 1000;
        }
    }else
    {
        for(int i = 0; i < Size; ++i)
        {
            printf("A[%i]: ", i);
            scanf("%i", &A[i]);
        }
    }
    printf("Algoritmo:\n1-Bubble\n2-Insertion\n3-Selection\n4-Merge\n5-Quick\n");
    scanf("%i", &x);

    switch(x)
    {
        case 1:
            BubbleSort(A, Size);
        break;
        case 2:
            InsertionSort(A, Size);
        break;
        case 3:
            SelectionSort(A, Size);
        break;
        case 4:
            MergeSort(A, 0, Size-1);
        break;
        case 5:
            QuickSort(A, 0, Size-1);
        break;
        default:
        break;
    }
    
    for(int i = 0; i < Size; ++i)
    {
        printf("%i, ", A[i]);
    }
    free(A);
}