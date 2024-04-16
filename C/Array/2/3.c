#include <stdio.h>
int main()
{
    int A[4][4] = 
    {
        {10, 12, 15, 22},
        {38, 46, 55, 60},
        {65, 35, 84, 10},
        {81, 14, 69, 56}
    };
    int soma;
    for(int i = 0; i < 4; ++i)
    {
        soma = 0;
        for(int j = 0; j < 4; ++j)
        {
            soma += A[i][j];
        }
        printf("Media Aluno %i: %i\n", i, soma/4);
    }
}