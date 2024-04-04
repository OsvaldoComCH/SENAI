#include <stdio.h>
int main()
{
    int i = -1;
    float f = 1.23;
    char c = '\\';

    int * pi = &i;
    float * pf = &f;
    char * pc = &c;

    printf("%i\n%f\n%c\n", i, f, c);

    *pi = *pi ^ 19283244;
    *pf = *pf - 23;
    *pc = '/';
    
    printf("%i\n%f\n%c\n", i, f, c);
}