#include <stdio.h>
void Comp(int * x, int * y)
{
    printf("Maior endereco: %x\n", (x < y) ? y: x);
    printf("Valor do maior endereco: %i", (x < y) ? *y: *x);
}
int main()
{
    int N1, N2;
    printf("Valor: ");
    scanf("%i", &N1);
    printf("Valor 2: ");
    scanf("%i", &N2);
    Comp(&N1, &N2);
}