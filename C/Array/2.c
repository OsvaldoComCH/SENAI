#include <stdio.h>
int main()
{
    int A[6] = {2, 17, 28, 29, 32, 44};
    int maior = 0;
    for(int i = 0; i < sizeof(A); ++i)
    {
        if(A[i] > maior){maior = A[i];}
    }
    printf("%i", maior);
}