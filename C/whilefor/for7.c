#include <stdio.h>
#include <math.h>
int main()
{
    unsigned int N, Count = 1;
    printf("Numero: ");
    scanf("%i", &N);
    int i = 1;
    for(; i < 10; ++i)
    {
        if(!(int) (N/=10)){break;}
    }
    printf("Digitos: %i", i);
}