#ifndef AGENDA_H
#define AGENDA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ENDERECO
{
    int CEP;
    unsigned short Numero;
    char Rua[30];
    char Complemento[16];
    char Bairro[20];
    char Cidade[20]; 
    char Pais[20];
    char Estado[20];
}ENDERECO;

typedef struct ANIVERSARIO
{
    unsigned char Dia;
    unsigned char Mes;
    unsigned short Ano;
}ANIVERSARIO;

typedef struct TELEFONE
{
    int Numero;
    unsigned char DDD;
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
    CONTATO * Contatos;
    int Size;
} AGENDA;

static inline void PrintDados(const CONTATO * Contato)
{
    printf("%s (%s):\n(%i) %i", 
    Contato->Nome, Contato->Email, Contato->Telefone.DDD, Contato->Telefone.Numero);
}

void CriarAgenda(AGENDA * Agenda)
{
    Agenda->Size = 0;
    Agenda->Contatos = malloc(1);
}

int CompAlfabetica(const char * S1, const char * S2)
{
    for(int i = 0; i < 20; ++i)
    {
        if((S1[i] | 0x20) == (S2[i] | 0x20)){continue;}
        return (S1[i] | 0x20) - (S2[i] | 0x20);
    }
    return 0;
}

void Sort(CONTATO * Contatos, int Start, int End)
{
    if(Start >= End){return;}
    int i = (Start);
  
    for(int j = Start; j <= End; ++j)
    {
        if(CompAlfabetica(Contatos[j].Nome, Contatos[End].Nome) < 0)
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
    Agenda->Contatos = (CONTATO *) realloc(Agenda->Contatos, sizeof(CONTATO)*Agenda->Size+1);
    Agenda->Contatos[Agenda->Size] = *Contato;
    Sort(Agenda->Contatos, 0, Agenda->Size);
    ++Agenda->Size;
}

void DelContato(AGENDA * Agenda, int DDD, int Telefone)
{
    int index = 0;
    --Agenda->Size;
    for(; index < Agenda->Size; ++index)
    {
        Agenda->Contatos[index] = Agenda->Contatos[index+1];
    }
    Agenda->Contatos = (CONTATO *) realloc(Agenda->Contatos, sizeof(CONTATO)*Agenda->Size);
}

static inline void PrintDadosFull(const CONTATO * Contato)
{
    printf("%s (%s):\n(%i) %i\tAniversario: %i/%i/%i\n%s, %i - %s, %s (%s)\n%s", 
    Contato->Nome, Contato->Email, Contato->Telefone.DDD, Contato->Telefone.Numero, Contato->Aniversario.Dia,
    Contato->Aniversario.Mes, Contato->Aniversario.Ano, Contato->Endereco.Rua, Contato->Endereco.Numero,
    Contato->Endereco.Bairro, Contato->Endereco.Cidade, Contato->Endereco.Estado, Contato->Observacao);
}

void PrintNome(const AGENDA * Agenda, const char * str)
{
    for(int i = 0; i < Agenda->Size; ++i)
    {
        if(strcmp(str, Agenda->Contatos[i].Nome))
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
#endif