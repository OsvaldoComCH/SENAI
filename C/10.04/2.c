#include <stdio.h>
int main()
{
    int x = 50;
    int * y = &x;
    *y = 1;
    printf("%i", x);
}