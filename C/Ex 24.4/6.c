#include <stdio.h>
#include <stdlib.h>
int main()
{
    char * Text1 = malloc(20);
    char * Text2 = malloc(20);
    char * Text3 = malloc(20);
    scanf("%s", Text1);
    scanf("%s", Text2);
    int i = 0;
    while(Text1[i] != '\0' && Text2 != '\0')
    {
        if(Text1[i] == Text2[i])
        {
            Text3[i] = Text1[i];
        }else
        {
            Text3[i] = '_';
        }
        ++i;
    }
    Text3[i] = '\0';
    printf("%s", &Text3);
    free(Text1);
    free(Text2);
    free(Text3);
}