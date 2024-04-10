#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
int main()
{
    srand(time(NULL));
    char Load[21] = "____________________";
    int i = 0;
    while(i < 21)
    {
        system("cls");
        printf("[%s]", Load);
        Load[i] = '#';
        ++i;
        Sleep(300 + rand() % 700);
        if(!(rand()%40))
        {
            Sleep(10000);
        }
    }
    printf("\nConluido");
}