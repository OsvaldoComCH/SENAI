#include <stdio.h>
#include <stdlib.h>
typedef struct Aluno
{
    float Notas[3];
    int Matricula;
    char Nome[20];
    char Curso[20];
} Aluno;

int main()
{
    Aluno Alunos[5];
    for(int i = 0; i < 5; ++i)
    {
        printf("\nAluno %i\nNome: ", i);
        scanf("%s", Alunos[i].Nome);
        printf("Curso: ");
        scanf("%s", Alunos[i].Curso);
        printf("Matricula: ");
        scanf("%i", &Alunos[i].Matricula);
        printf("Nota 1: ");
        scanf("%f", &Alunos[i].Notas[0]);
        printf("Nota 2: ");
        scanf("%f", &Alunos[i].Notas[1]);
        printf("Nota 3: ");
        scanf("%f", &Alunos[i].Notas[2]);
    }
    float MaiorNota = 0, MaiorMedia = 0, MenorMedia = 0xffffffff;
    Aluno * AMaiorNota, * AMaiorMedia, * AMenorMedia;
    for(int i = 0; i < 5; ++i)
    {
        if(Alunos[i].Notas[0] > MaiorNota)
        {
            MaiorNota = Alunos[i].Notas[0];
            AMaiorNota = &Alunos[i];
        }
        float Media = (Alunos[i].Notas[0] + Alunos[i].Notas[1] + Alunos[i].Notas[2]) / 3;
        if(Media > MaiorMedia)
        {
            MaiorMedia = Media;
            AMaiorMedia = &Alunos[i];
        }
        if(Media < MenorMedia)
        {
            MenorMedia = Media;
            AMenorMedia = &Alunos[i];
        }
        printf("\nAluno %i:\nMedia: %.1f\n%s\n", i+1, Media, Media >= 6 ? "Aprovado" : "Reprovado");
    }
    printf("Maior Nota 1: %s\n", AMaiorNota->Nome);
    printf("Maior Media: %s\n", AMaiorMedia->Nome);
    printf("Menor Media: %s\n", AMenorMedia->Nome);
}