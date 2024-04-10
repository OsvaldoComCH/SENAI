#include <stdio.h>
int main()
{
    int N;
    printf("Numero: ");
    scanf("%i", &N);
    for(int i = N; i <= 100; i += N)
    {
        printf("%i\n", i);
    }
}