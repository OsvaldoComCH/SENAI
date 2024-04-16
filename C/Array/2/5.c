#include <stdio.h>
int main()
{
    char A[3][2] = {{'a','B'},{'b','A'},{'c','C'}};
    int x[3];
    for(int i = 0; i < 3; ++i)
    {
        printf("%i - %c\t%c\n", i+1, A[i][0], A[i][1]);
    }
    for(int i = 0; i < 3; ++i)
    {
        printf("%i- ", i+1);
        scanf("%i", &x[i]);
    }
    if(x[0] == 2 && x[1] == 1 && x[2] == 3)
    {
        printf("Acertou");
    }else
    {
        printf("Errou");
    }
}