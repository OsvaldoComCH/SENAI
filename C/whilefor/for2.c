#include <stdio.h>
int main()
{
    int N1, N2 = 0;
    printf("Numero: ");
    scanf("%i", &N1);
    for(int i = 0; i <= N1; ++i)
    {
        N2 += i;
    }
    printf("%i\n", N2);
}