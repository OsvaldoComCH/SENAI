#include <stdio.h>
int main()
{
    int N;
    printf("Numero: ");
    scanf("%i", &N);
    if(N > 20){N = 20;}
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            printf("* ");
        }
        printf("\n");
    }
}