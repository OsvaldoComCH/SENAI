#include <stdio.h>
#include <stdlib.h>
typedef struct Horario
{
    int Horas, Minutos, Segundos;
} Horario;
typedef struct Data
{
    int Ano, Mes, Dia;
} Data;
typedef struct Compromisso
{
    Data Data;
    Horario Horario;
    char Detalhes[50];
} Compromisso;

static inline void Format(const Compromisso C)
{
    printf("%s:\n%i/%i/%i\n%i:%i\n", C.Detalhes, C.Data.Dia, C.Data.Mes, C.Data.Ano, C.Horario.Horas, C.Horario.Minutos);
}

int main()
{
    Compromisso	C1 = {{2024, 5, 7}, {8, 0, 0}, "Bom Dia"}, C2;
    printf("Descricao: ");
    scanf("%s", C2.Detalhes);
    printf("Ano: ");
    scanf("%i", &C2.Data.Ano);
    printf("Mes: ");
    scanf("%i", &C2.Data.Mes);
    printf("Dia: ");
    scanf("%i", &C2.Data.Dia);
    printf("Hora: ");
    scanf("%i", &C2.Horario.Horas);
    printf("Minutos: ");
    scanf("%i", &C2.Horario.Minutos);
    Format(C1);
    Format(C2);
}