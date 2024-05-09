#include <stdio.h>
void Sort(int * P, int Start, int End)
{
    if(Start >= End){return;}
    int Pivot = P[End];
    int i = Start;
  
    for(int j = Start; j <= End; ++j)
    {
        if(P[j]<Pivot)
        {
            int Temp = P[i];
            P[i] = P[j];
            P[j] = Temp;
            ++i;
            for(int x = 0; x < 16; ++x)
            {
                printf("%i, ", P[x]);
            }
            printf("\n");
        }
    }
    int Temp = P[i];
    P[i] = P[End];
    P[End] = Temp;
    for(int x = 0; x < 16; ++x)
    {
        printf("%i, ", P[x]);
    }
    printf("\n");

    Sort(P, Start, i - 1);
    Sort(P, i + 1, End);
}

int main()
{
    int A[16] = 
    {
        2, 3, 5, 6, 8, 9, 10, 12, 13, 7, 16, 1, 14, 4, 15, 11
    };
    Sort(A, 0, 15);
    for(int i = 0; i < 16; ++i)
    {
        printf("%i, ", A[i]);
    }
}