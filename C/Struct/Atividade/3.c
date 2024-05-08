#include <stdio.h>
#include <stdlib.h>
typedef struct Pessoa
{
    char Nome[20];
    char Endereco[50];
    char Telefone[10];
} Pessoa;

int CompAlfabetica(const char * S1, const char * S2)
{
    for(int i = 0; i < 20; ++i)
    {
        if((S1[i] | 0x20) == (S2[i] | 0x20)){continue;}
        return (S1[i] | 0x20) - (S2[i] | 0x20);
    }
    return 0;
}

void Sort(Pessoa * P, int Start, int End)
{
    if(Start >= End){return;}
    Pessoa Pivot = P[End];
    int i = (Start-1);
  
    for(int j = Start; j <= End; ++j)
    {
        if(CompAlfabetica(P[j].Nome, Pivot.Nome) < 0)
        {
            ++i;
            Pessoa Temp = P[i];
            P[i] = P[j];
            P[j] = Temp;
        }
    }
    ++i;
    Pessoa Temp = P[i];
    P[i] = P[End];
    P[End] = Temp;

    Sort(P, Start, i - 1);
    Sort(P, i + 1, End);
}

int main()
{
    Pessoa A[5];
    for(int i = 0; i < 5; ++i)
    {
        printf("Pessoa %i:\n", i+1);
        printf("Nome: ");
        fgets(A[i].Nome, 19, stdin);
        printf("Endereco: ");
        fgets(A[i].Endereco, 49, stdin);
        printf("Telefone: ");
        fgets(A[i].Telefone, 9, stdin);
        printf("\n");
    }
    Sort(A, 0, 4);
    for(int i = 0; i < 5; ++i)
    {
        printf("%s\n", A[i].Nome);
    }
}