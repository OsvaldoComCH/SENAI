#include <stdio.h>
int main()
{
    int N, P;
    printf("Numero: ");
    scanf("%i", &N);
    for(int i = 2; i <= N; ++i)
    {
        P = 0;
        for(int j = 2; j <= i/2; ++j)
        {
            if(!(i % j))
            {
                P = 1;
            }
        }
        if(!P)
        {
            printf("%i\n", i);
        }
    }
}