#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Agenda.h"

void NovoContato(AGENDA * Agenda)
{
    CONTATO New;
    printf("Nome: ");
    scanf(" %19[^\n]", New.Nome);

    printf("Telefone\n");
    printf("DDD: ");
    scanf("%i", &New.Telefone.DDD);
    printf("Numero: ");
    scanf("%i", &New.Telefone.Numero);
    printf("Email: ");
    scanf(" %29[^\n]", New.Email);

    printf("Endereco\n");
    printf("Rua: ");
    scanf(" %29[^\n]s", New.Endereco.Rua);
    printf("Numero: ");
    scanf("%i", &New.Endereco.Numero);
    printf("CEP: ");
    scanf("%i", &New.Endereco.CEP);
    printf("Complemento: ");
    scanf(" %15[^\n]", New.Endereco.Complemento);
    printf("Bairro: ");
    scanf(" %19[^\n]", New.Endereco.Bairro);
    printf("Cidade: ");
    scanf(" %19[^\n]", New.Endereco.Cidade);
    printf("Estado: ");
    scanf(" %19[^\n]", New.Endereco.Estado);
    printf("Pais: ");
    scanf(" %19[^\n]", New.Endereco.Pais);

    printf("Aniversario\n");
    printf("Dia: ");
    scanf("%i", &New.Aniversario.Dia);
    printf("Mes: ");
    scanf("%i", &New.Aniversario.Mes);
    printf("Ano: ");
    scanf("%i", &New.Aniversario.Ano);
    printf("Observacao:\n");
    scanf(" %99[^\n]", New.Observacao);
    fflush(stdin);
    AddContato(Agenda, &New);
}

int main()
{
    AGENDA Agenda;
    CriarAgenda(&Agenda);
    int x;
    while(1)
    {
        printf("1- Adicionar Contato\n2- Remover Contato\n3- Buscar Contato\n0- Sair\n");
        scanf("%i", &x);
        if(!x){break;}
        if(x == 1)
        {
            NovoContato(&Agenda);
            continue;
        }
        if(x == 2)
        {
            int DDD, Numero;
            printf("DDD: ");
            scanf("%i", &DDD);
            printf("Numero: ");
            scanf("%i", &Numero);
            DelContato(&Agenda, DDD, Numero);
            continue;
        }
        if(x == 3)
        {
            printf("Modo de Busca\n1- Nome\n2- Mes Aniversario\n3- Dia Aniversario\n4- Telefone\n0- Voltar\n");
            scanf("%i", &x);
            if(x == 1)
            {
                char Nome[20];
                printf("Nome: ");
                scanf(" %19[^\n]", Nome);
                PrintNome(&Agenda, Nome);
            }else
            if(x == 2)
            {
                int Mes;
                printf("Mes: ");
                scanf("%i", &Mes);
                PrintMesAniversario(&Agenda, Mes);
            }else
            if(x == 3)
            {
                int Dia, Mes;
                printf("Dia: ");
                scanf("%i", &Dia);
                printf("Mes: ");
                scanf("%i", &Mes);
            }else
            if(x == 4)
            {
                int DDD, Numero;
                printf("DDD: ");
                scanf("%i", &DDD);
                printf("Numero: ");
                scanf("%i", &Numero);
                PrintTelefone(&Agenda, DDD, Numero);
            }
            continue;
        }
    }
    DeletarAgenda(&Agenda);
}