#include <stdio.h>
int Maior(int Vetor[], int Tamanho)
{
    int Maior = 0;
    for(int i = 0; i < Tamanho; ++i)
    {
        if(Vetor[i] > Maior)
        {
            Maior = Vetor[i];
        }
    }
    return Maior;
}
int main()
{
    int x[10] = {7, 10, 23, 24, 27, 40, 41, 56, 58, 60};
    printf("%i", Maior(x, 10));
}