#include <stdio.h>
void DoubleInt(int * Number)
{
    *Number = *Number << 1;
}
int main()
{
    int x;
    printf("Numero: ");
    scanf("%i", &x);
    DoubleInt(&x);
    printf("%i", x);
}