#include <stdio.h>
int main()
{
    float Temp;
    int i;
    printf("Converter:\n0 - C para F\n1 - F para C\n");
    scanf("%i", &i);
    printf("Temperatura: ");
    scanf("%f", &Temp);

    printf("Conversao: %.1f\n", (i) ? ((Temp-32)/1.8):(Temp*1.8+32));
    switch((((i) ? (Temp = (Temp-32)/1.8):(Temp)) < 0) ? -1 : (int) Temp/16)
    {
        case -1:
            printf("Temperatura abaixo de zero");
            break;
        case 0:
            printf("Esta frio");
            break;
        case 1:
            printf("Temperatura boa");
            break;
        default:
            printf("Esta muito quente");
            break;
    }
}