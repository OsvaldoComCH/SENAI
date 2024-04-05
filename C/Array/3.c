#include <stdio.h>

typedef struct
{
    char Nome[20];
    int Notas[3];
} Aluno;
int main()
{
    FILE * File = fopen("./dados.txt", "w+");
    Aluno A;
    while(1)
    {
        
    }
    fclose(File);
}