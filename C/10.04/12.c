#include <stdio.h>
int main()
{
    int x[5] = {1,2,3,4,5};
    int *y = x;
    *(y+2) = 6;

    for(int i = 0; i < 5; ++i)
    {
        printf("%i\n", x[i]);
    }
}