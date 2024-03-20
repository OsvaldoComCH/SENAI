#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
int main()
{
    srand(time(NULL));
    unsigned int N1 = rand() % 1000 + 1, N2 = 0xffff;
    while(N1 != N2 && N2)
    {
        printf("Numero (0 para desistir): ");
        scanf("%i", &N2);
    }
    if(N2)
    {
        printf("Acertou");
        for(int i = 0; i < 5; ++i)
        {
            system("color 17");
            Sleep(50);
            system("color 27");
            Sleep(50);
            system("color 47");
            Sleep(50);
            system("color 57");
            Sleep(50);
            system("color A7");
            Sleep(50);
        }
            system("color 07");
    }else
    {
        printf("Errou");
    }
}