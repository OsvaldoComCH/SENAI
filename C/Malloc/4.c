#include <stdio.h>
#include <stdlib.h>
int main()
{
    int L, C;
    printf("Linhas: ");
    scanf("%i", &L);
    int ** Matrix = (int **) malloc(L*sizeof(int*));
    printf("Colunas: ");
    scanf("%i", &C);
    for(int i = 0; i < L; ++i)
    {
        Matrix[i] = (int *) malloc(C*sizeof(int));
        for(int j = 0; j < C; ++j)
        {
            printf("Valor [%i][%i]: ", i, j);
            scanf("%i", &Matrix[i][j]);
        }
    }
    for(int i = 0; i < L; ++i)
    {
        for(int j = 0; j < C; ++j)
        {
            printf("[%i]", Matrix[i][j]);
        }
        printf("\n");
        free(Matrix[i]);
    }
    free(Matrix);
}