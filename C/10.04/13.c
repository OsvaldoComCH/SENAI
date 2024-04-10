#include <stdio.h>
void Remover(int Vetor[], int Tamanho, int Indice)
{
    int c;
    for(; Indice < Tamanho-1; ++Indice)
    {
        Vetor[Indice] = Vetor[Indice+1];
    }
    Vetor[Tamanho-1] = 0;
}
int main()
{
    int x[10] = {7, 10, 23, 24, 27, 40, 41, 56, 58, 60};
    Remover(x, 10, 2);
    for(int i = 0; i < sizeof(x)/4; ++i)
    {
        printf("%i\n", x[i]);
    }
}