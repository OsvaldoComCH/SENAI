#include <stdio.h>
#include <Windows.h>
#include <string.h>
char Palavra[2][11] = {"radiologia", "----------"};
int Tentativas = 6;
char Letra;
int CheckLetter()
{
    int ret = 0;
    for(int i = 0; i < 11; ++i)
    {
        if(!((Letra | 32) ^ Palavra[0][i]))
        {
            Palavra[1][i] = Palavra[0][i];
            ++ret;
        }
    }
    return ret;
}
void Input()
{
    system("cls");
    printf("Tu tens %i tentativas\n[ %s ]\n\nUma letra: ", Tentativas, Palavra[1]);
    scanf(" %c", &Letra);
}
int main()
{
    while(Tentativas)
    {
        Input();
        if(CheckLetter())
        {
            if(!strcmp(Palavra[0], Palavra[1]))
            {
                break;
            }
        }else
        {
            --Tentativas;
        }
    }
    system("cls");
    printf("%s\n[ %s ]\n", Tentativas ? "Acertou!":"Errado, a palavra correta era:", Palavra[0]);
}