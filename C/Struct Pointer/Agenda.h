#ifndef AGENDA_H
#define AGENDA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ENDERECO
{
    int CEP;
    int Numero;
    char Rua[30];
    char Complemento[16];
    char Bairro[20];
    char Cidade[20]; 
    char Pais[20];
    char Estado[20];
}ENDERECO;

typedef struct ANIVERSARIO
{
    int Dia;
    int Mes;
    int Ano;
}ANIVERSARIO;

typedef struct TELEFONE
{
    int Numero;
    int DDD;
}TELEFONE;


typedef struct CONTATO 
{
    ENDERECO Endereco;
    ANIVERSARIO Aniversario;
    TELEFONE Telefone;
    char Nome[20];
    char Email[30];
    char Observacao[100];
}CONTATO;

typedef struct AGENDA
{
    int Size;
    CONTATO * Contatos;
} AGENDA;

static inline void PrintDados(const CONTATO * Contato)
{
    printf("%s (%s):\n(%i) %i\n", 
    Contato->Nome, Contato->Email, Contato->Telefone.DDD, Contato->Telefone.Numero);
}

void CriarAgenda(AGENDA * Agenda)
{
    Agenda->Size = 0;
    Agenda->Contatos = (CONTATO *) malloc(sizeof(CONTATO));
}

void DeletarAgenda(AGENDA * Agenda)
{
    free(Agenda->Contatos);
}

void Sort(CONTATO * Contatos, int Start, int End)
{
    if(Start >= End){return;}
    int i = (Start);

    for(int j = Start; j <= End; ++j)
    {
        if(strcmp(Contatos[j].Nome, Contatos[End].Nome) < 0)
        {
            ++i;
            CONTATO Temp = Contatos[i];
            Contatos[i] = Contatos[j];
            Contatos[j] = Temp;
        }
    }
    ++i;
    CONTATO Temp = Contatos[i];
    Contatos[i] = Contatos[End];
    Contatos[End] = Temp;

    Sort(Contatos, Start, i - 1);
    Sort(Contatos, i + 1, End);
}

void AddContato(AGENDA * Agenda, const CONTATO * Contato)
{
    /*if(Agenda->Size == 0)
    {
        Agenda->Contatos = (CONTATO *) malloc(sizeof(CONTATO));
    }else
    {*/
        Agenda->Contatos = (CONTATO *) realloc(Agenda->Contatos, sizeof(CONTATO)*(Agenda->Size+2));
    //}
    Agenda->Contatos[Agenda->Size] = *Contato;
    Sort(Agenda->Contatos, 0, Agenda->Size);
    ++Agenda->Size;
}

void DelContato(AGENDA * Agenda, int DDD, int Numero)
{
    int i = 0;
    char c = '_';
    for(; i < Agenda->Size; ++i)
    {
        if(Agenda->Contatos[i].Telefone.DDD == DDD && Agenda->Contatos[i].Telefone.Numero == Numero)
        {
            PrintDados(&Agenda->Contatos[i]);
            printf("Deseja deletar este contato (s/n)? ");
            scanf(" %c", &c);
            if(c == 's')
            {
                break;
            }else
            {
                continue;
            }
        }
    }
    if(c != 's')
    {
        if(c == '_')
        {
            printf("Contato não encontrado");
        }
        return;
    }
    --Agenda->Size;
    for(; i < Agenda->Size; ++i)
    {
        Agenda->Contatos[i] = Agenda->Contatos[i+1];
    }
    Agenda->Contatos = (CONTATO *) realloc(Agenda->Contatos, sizeof(CONTATO)*Agenda->Size);
}

static inline void PrintDadosFull(const CONTATO * Contato)
{
    printf("%s (%s):\n(%i) %i\tAniversario: %i/%i/%i\n%s, %i - %s, %s (%s)\n%s\n", 
    Contato->Nome, Contato->Email, Contato->Telefone.DDD, Contato->Telefone.Numero, Contato->Aniversario.Dia,
    Contato->Aniversario.Mes, Contato->Aniversario.Ano, Contato->Endereco.Rua, Contato->Endereco.Numero,
    Contato->Endereco.Bairro, Contato->Endereco.Cidade, Contato->Endereco.Estado, Contato->Observacao);
}

void PrintNome(const AGENDA * Agenda, const char * str)
{
    for(int i = 0; i < Agenda->Size; ++i)
    {
        if(strcmp(str, Agenda->Contatos[i].Nome) == 0)
        {
            PrintDados(&Agenda->Contatos[i]);
        }
    }
}

void PrintMesAniversario(const AGENDA * Agenda, int Mes)
{
    for(int i = 0; i < Agenda->Size; ++i)
    {
        if(Mes == Agenda->Contatos[i].Aniversario.Mes)
        {
            PrintDadosFull(&Agenda->Contatos[i]);
        }
    }
}

void PrintDiaAniversario(const AGENDA * Agenda, int Mes, int Dia)
{
    for(int i = 0; i < Agenda->Size; ++i)
    {
        if(Mes == Agenda->Contatos[i].Aniversario.Mes && Dia == Agenda->Contatos[i].Aniversario.Dia)
        {
            PrintDadosFull(&Agenda->Contatos[i]);
        }
    }
}

void PrintTelefone(const AGENDA * Agenda, int DDD, int Numero)
{
    for(int i = 0; i < Agenda->Size; ++i)
    {
        if(DDD == Agenda->Contatos[i].Telefone.DDD && Numero == Agenda->Contatos[i].Telefone.Numero)
        {
            PrintDadosFull(&Agenda->Contatos[i]);
        }
    }
}
#endif