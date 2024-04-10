#include <stdio.h>
void Dobrar(int Vetor[], int Tamanho)
{
    for(int i = 0; i < Tamanho; ++i)
    {
        Vetor[i] = Vetor[i] << 1;
    }
}
int main()
{
    int x[10] = {7, 10, 23, 24, 27, 40, 41, 56, 58, 60};
    Dobrar(x, sizeof(x)/4);
    for(int i = 0; i < sizeof(x)/4; ++i)
    {
        printf("%i\n", x[i]);
    }
}