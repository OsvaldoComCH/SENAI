#include <stdio.h>
int main()
{
    float Saldo = 0;
    int x;
    while(1)
    {
        printf("1-deposito\n2-saque\n0-sair\n");
        scanf("%i", &x);
        if(!x)
        {
            break;
        }else
        if(x==1)
        {
            float Valor;
            printf("Valor: ");
            scanf("%f", &Valor);
            Saldo += Valor;
        }else
        {
            if(Saldo < 60)
            {
                printf("Saldo insuficiente\n");
            }else
            {
                float Valor;
                printf("Valor: ");
                scanf("%f", &Valor);
                if(Valor < 60)
                {
                    printf("Saque muito pequeno\n");
                }else
                if(Valor > Saldo)
                {
                    printf("Saldo insuficiente\n");
                }
            }
        }
    }
}