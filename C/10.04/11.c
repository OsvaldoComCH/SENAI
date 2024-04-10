#include <stdio.h>
void Inverter(int Vetor[], int Tamanho)
{
    int c;
    for(int i = 0; i < Tamanho/2; ++i)
    {
        c = Vetor[Tamanho-i-1];
        Vetor[Tamanho-i-1] = Vetor[i];
        Vetor[i] = c;
    }
}
int main()
{
    int x[10] = {7, 10, 23, 24, 27, 40, 41, 56, 58, 60};
    Inverter(x, 10);
    for(int i = 0; i < sizeof(x)/4; ++i)
    {
        printf("%i\n", x[i]);
    }
}