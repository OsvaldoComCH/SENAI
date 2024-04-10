#include <stdio.h>
int SomarVetor(int Vetor[], int Tamanho)
{
    int Soma = 0;
    for(int i = 0; i < Tamanho; ++i)
    {
        Soma += Vetor[i];
    }
    return Soma;
}
int main()
{
    int x[10] = {7, 10, 23, 24, 27, 40, 41, 56, 58, 60};
    printf("%i", SomarVetor(x, 10));
}