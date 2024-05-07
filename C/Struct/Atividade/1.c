#include <stdio.h>
#include <stdlib.h>
typedef struct Aluno
{
    float Nota1, Nota2;
    int Matricula;
    int IdCurso;
    char Nome[20];
} Aluno;

int main()
{
    Aluno Alunos[10];
    float Medias[10];
    for(int i = 0; i < 10; ++i)
    {
        printf("\nAluno %i\nNome: ", i);
        scanf("%s", Alunos[i].Nome);
        printf("Curso: ");
        scanf("%i", &Alunos[i].IdCurso);
        printf("Matricula: ");
        scanf("%i", &Alunos[i].Matricula);
        printf("Nota 1: ");
        scanf("%f", &Alunos[i].Nota1);
        printf("Nota 2: ");
        scanf("%f", &Alunos[i].Nota2);
        Medias[i] = (Alunos[i].Nota1 + Alunos[i].Nota2 * 2) / 3;
    }

    for(int i = 0; i < 10; ++i)
    {
        printf("\nAluno %i\nNome: %s\nMedia: %.1f", i, Alunos[i].Nome, Medias[i]);
    }
}