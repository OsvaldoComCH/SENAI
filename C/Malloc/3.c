#include <stdio.h>
#include <stdlib.h>
int main()
{
    int Size;
    printf("Tamanho: ");
    scanf("%i", &Size);
    char * Text = (char *) malloc(Size);
    printf("String:\n");
    scanf("%s", Text);
    printf("%s", Text);
    free(Text);
}