#include <stdio.h>

int main()
{
    int N1, N2, Op;
    printf("Numero: ");
    scanf("%i", &N1);
    
    printf("Operador:\n1-NOT\n2-AND\n3-OR\n4-XOR\n5-SHIFT\n");
    scanf("%i", &Op);
    switch(Op)
    {
        case 1:
            printf("~%i = %i", N1, ~N1);
            return 0;
        break;
        case 2:
        case 3:
        case 4:
            printf("Segundo Numero: ");
            scanf("%i", &N2);
        break;
        case 5:
            printf("Direcao:\n1-Esquerda\n2-Direita\n");
            scanf("%i", &Op);
            if(Op != 2){printf("Direcao invalida, direita sera usada\n");}
            printf("Quantidade de casas: ");
            scanf("%i", &N2);
            if(Op == 1)
            {
                printf("%i << %i = %i", N1, N2, N1 << N2);
            }else
            {
                printf("%i >> %i = %i", N1, N2, N1 >> N2);
            }
            return 0;
        break;
        default:
            printf("Operador invalido");
            return 0;
        break;
    }
    switch(Op)
    {
        case 2:
            printf("%i & %i = %i", N1, N2, N1 & N2);
        break;
        case 3:
            printf("%i | %i = %i", N1, N2, N1 | N2);
        break;
        case 4:
            printf("%i ^ %i = %i", N1, N2, N1 ^ N2);
        break;
    }
}