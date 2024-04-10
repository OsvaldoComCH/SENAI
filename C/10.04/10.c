#include <stdio.h>
int Funcao(int N)
{
    return ~N;
}
int main()
{
    int (* Func)(int) = Funcao;
    (*Func)(10);
    printf("%i", (*Func)(10));
}