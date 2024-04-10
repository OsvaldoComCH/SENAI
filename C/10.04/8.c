#include <stdio.h>
int ContarElementos(int Vetor[], int Tamanho, int Numero)
{
    for(int i = 0; i < Tamanho; ++i)
    {
        if(Vetor[i] == Numero)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int x[10] = {7, 10, 23, 24, 27, 40, 41, 56, 58, 60}, N;
    scanf("%i", &N);
    printf("%i", ContarElementos(x, 10, N));
}