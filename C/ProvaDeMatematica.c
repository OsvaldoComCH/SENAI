#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    FILE *File = fopen("./respostas.txt", "w");
    srand((unsigned int) time(NULL));
    int N1, N2, Res, Acertos = 0;
    for (int i = 0; i < 5; ++i)
    {
        N1 = rand() % 100 + 1; 
        N2 = rand() % 100 + 1;
        printf("Qual a soma de %i + %i?\nR: ", N1, N2);
        scanf("%i", &Res);
        if(Res - (N1 + N2))
        {
            printf("Errou\n");
        }else
        {
            printf("Acertou\n");
            Acertos++;
        }
        fprintf(File, "%i + %i = %i\n", N1, N2, N1+N2);
    }
    fprintf(File, "Acertos: %i", Acertos);
    fclose(File);
}