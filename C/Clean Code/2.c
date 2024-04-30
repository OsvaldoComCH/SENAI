#include <stdio.h>
int main()
{
    int num;
    unsigned long long fatorial = 1;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &num);
    if(num < 0)
    {
        printf("Erro! Fatorial de número negativo não existe.");
    }else
    {
        for(int i = 1; i <= num; ++i)
        {
            fatorial *= i;
        }
        printf("Fatorial de %d = %llu", num, fatorial);
    }
    return 0;
}