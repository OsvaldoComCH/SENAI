#include <stdio.h>
int main()
{
    unsigned int x, y, Notas[3][3] = {0,0,0,0,0,0,0,0,0};
    while(1)
    {    
        printf("1- Matematica\n2- Portugues\n3- Programacao\n0- Sair\n");
        scanf("%i", &x);
        if(!x){break;}
        if(--x > 2){x = 2;}
        printf("%s\n", x ? (x==1 ? "Portugues" : "Programacao") : "Matematica");
        while(1)
        {
            for(int i = 0; i < 3; ++i)
            {
                printf("%i- Nota %i: %i\n", i+1, i+1, Notas[x][i]);
            }
            printf("0- Voltar\n");
            scanf("%i", &y);
            if(!y){break;}
            if(--y > 2){y = 2;}
            printf("Valor: ");
            scanf("%i", &Notas[x][y]);
        }
    }
}