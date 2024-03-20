#include <stdio.h>
int main()
{
    int N1 = 1,N2 = 2,N3 = 3;
    while(N1 + N2 + N3 != 45)
    {
        printf("Numero 1: ");
        scanf("%i", &N1);
        printf("Numero 2: ");
        scanf("%i", &N2);
        printf("Numero 3: ");
        scanf("%i", &N3);
    }
}