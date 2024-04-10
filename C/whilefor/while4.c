#include <stdio.h>
int main()
{
    int Pass = 0;
    while(1)
    {
        printf("Senha: ");
        scanf("%i", &Pass);
        if(Pass != 1234)
        {
            printf("Esta nao era a senha\n");
        }else
        {
            break;
        }
    }
    printf("Esta era a senha\n");
}