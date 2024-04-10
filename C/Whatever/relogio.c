#include <stdio.h>
#include <time.h>
#include <windows.h>

void Temporizador(int seconds)
{
    time_t Time = time(NULL);
    while(Time + seconds > time(NULL))
    {
        Sleep(500);
        system("cls");
        printf("%i", (int) time(NULL) - Time);
    }
}

void Cronometro(int seconds)
{
    time_t Time = time(NULL);
    while(Time + seconds > time(NULL))
    {
        Sleep(1000);
        system("cls");
        printf("%i", (int) (Time + seconds) - time(NULL));
    }
}

void Hora()
{
    time_t Time = time(NULL);
    printf(ctime(&Time));
}

int main()
{
    int N;
    while(1)
    {
        printf("1-Cronometro\n2-Temporizador\n3-Hora Atual\n0-Sair\n");
        scanf("%i", &N);
        system("cls");
        switch(N)
        {
            case 1:
                printf("Segundos: ");
                scanf("%i", &N);
                Cronometro(N);
            break;
            case 2:
                printf("Segundos: ");
                scanf("%i", &N);
                Temporizador(N);
            break;
            case 3:
                Hora();
            break;
            default:
            return 0;
        }
        Sleep(3000);
        system("cls");
    }
}