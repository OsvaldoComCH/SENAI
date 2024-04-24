#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE * File = fopen("Texto.txt", "r+");
    int Size = 1;
    rewind(File);
    while(fgetc(File) != EOF){++Size;}
    char * Text = (char *) malloc(Size);
    rewind(File);
    fread(Text, 1, Size, File);
    Text[Size-1] = '\0';
    printf("%s", Text);
    free(Text);
    fclose(File);
}