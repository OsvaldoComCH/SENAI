#include <stdio.h>
int main()
{
    int P;
    for(int i = 2; i <= 100; ++i)
    {
        for(int j = 2; j <= i/2; ++j)
        {
            if(!(i % j))
            {
                P = 1;
            }
        }
        if(!P)
        {
            printf("%i\n", i);
        }
    }
}