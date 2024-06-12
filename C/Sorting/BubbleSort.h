#ifndef BUBBLE_SORT
#define BUBBLE_SORT

void BubbleSort(int * A, int Size)
{
    for(int i = 0; i < Size; ++i)
    {
        for(int j = 0; j < Size; ++j)
        {
            if(A[i] < A[j])
            {
                A[i] = A[j] ^ A[i];
                A[j] = A[j] ^ A[i];
                A[i] = A[j] ^ A[i];
            }
        }
    }
}

#endif