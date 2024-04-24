#ifndef HEADER1
#define HEADER1
#include <stdio.h>
    void PrintArray(const int * Arr, int Len)
    {
        for(int i = 0; i < Len; ++i)
        {
            printf("[%i]", Arr[i]);
        }
    }
#endif