#include <stdio.h>
int main(){
    char operador;
    float num1, num2;
    printf("Digite um operador (+, -, *, /): ");
    scanf(" %c", &operador);
    printf("Digite dois números: ");
    scanf("%f %f", &num1, &num2);
    switch(operador){
        //Adição
        case '+':
            printf("%.2f + %.2f = %.2f", num1, num2, num1+num2);
        break;
        //Subtração
        case '-':
            printf("%.2f - %.2f = %.2f", num1, num2, num1-num2);
        break;
        //Multiplicação
        case '*':
            printf("%.2f * %.2f = %.2f", num1, num2, num1*num2);
        break;
        //Divisão
        case '/':
            //Tratamento de divisão por zero
            if(num2!=0)
            {
                printf("%.2f / %.2f = %.2f", num1, num2, num1/num2);
            }else
            {
                printf("Erro! Divisão por zero!");
            }
        break;
        default:
            //Tratamento de operador inválido
            printf("Erro! Operador inválido!");
        break;
    }
    return 0;
}