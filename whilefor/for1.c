#include <stdio.h>
int main()
{
    int N;
    printf("Numero: ");
    scanf("%i", &N);
    for(int i = 0; i <= N; i+=2)
    {
        printf("%i\n", i);
    }
}