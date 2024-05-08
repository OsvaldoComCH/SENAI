#include <stdio.h>
#include <stdlib.h>
typedef struct Pessoa
{
    char Nome[20], Sexo, CPF[14], Cargo[50];
    float Salario;
    int DataNasc, Idade;
} Pessoa;

int main()
{
    Pessoa F;
    printf("Nome: ");
    scanf("%s", F.Nome);
    printf("Sexo: ");
    scanf(" %c", &F.Sexo);
    printf("Data de Nascimento: ");
    scanf("%i", &F.DataNasc);
    printf("Idade: ");
    scanf("%i", &F.Idade);
    printf("CPF: ");
    scanf("%s", F.CPF);
    printf("Cargo: ");
    scanf("%s", F.Cargo);
    printf("Salario: ");
    scanf("%f", &F.Salario);

    FILE * File = fopen("Out.txt", "w");
    fprintf(File, "%s (%c): CPF: %s\n%s\nSalario: %.2f\nIdade: %i", F.Nome, F.Sexo, F.CPF, F.Cargo, F.Salario, F.Idade);
}