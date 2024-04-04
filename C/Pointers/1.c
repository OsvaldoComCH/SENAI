#include <stdio.h>
void Swap(int * x, int * y)
{
    int i = *x;
    *x = *y;
    *y = i;
}
int main()
{
    int N1, N2;
    printf("Valor: ");
    scanf("%i", &N1);
    printf("Valor 2: ");
    scanf("%i", &N2);
    printf("N1 = %i, N2 = %i\n", N1, N2);
    Swap(&N1, &N2);
    printf("N1 = %i, N2 = %i", N1, N2);
}