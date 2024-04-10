#include <stdio.h>
void ContarElementos(int Vetor[], int Tamanho)
{
    int Par = 0, Impar = 0;
    for(int i = 0; i < Tamanho; ++i)
    {
        if(Vetor[i] % 2)
        {
            ++Impar;
        }else
        {
            ++Par;
        }
    }
    printf("Par: %i\nImpar: %i", Par, Impar);
}
int main()
{
    int x[10] = {7, 10, 23, 24, 27, 40, 41, 56, 58, 60};
    ContarElementos(x, 10);
}