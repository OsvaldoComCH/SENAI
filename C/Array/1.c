#include <stdio.h>
int main()
{
    int A[6] = {2, 17, 28, 29, 32, 44};
    int soma = 0;
    for(int i = 0; i < sizeof(A); ++i)
    {
        soma += A[i];
    }
    printf("%i", soma);
}