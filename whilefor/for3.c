#include <stdio.h>
int main()
{
    int N;
    printf("Numero: ");
    scanf("%i", &N);
    for(int i = 1; i <= 10; ++i)
    {
        printf("%i * %i = %i\n", N, i, N*i);   
    }
}