#include <stdio.h>
int main()
{
    int N;
    float Media = 0;
    for(int i = 1; i < 6; ++i)
    {
        printf("Numero %i: ", i);
        scanf("%i", &N);
        Media += N;
    }
    printf("Media: %.1f", Media/5);
}