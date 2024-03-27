#ifndef BANCO
#define BANCO
#include <stdio.h>
float Deposito(float Saldo, float ValorDeposito)
{
    FILE * File = fopen("out.txt", "a");
    fprintf(File, "Deposito realizado no valor de R$ %.2f\n", ValorDeposito);
    fclose(File);
    return Saldo + ValorDeposito;
}
float Saque(float Saldo, float ValorSaque)
{
    FILE * File = fopen("out.txt", "a");
    if(ValorSaque <= Saldo)
    {
        fprintf(File, "Saque realizado no valor de R$ %.2f\n", ValorSaque);
        fclose(File);
        return Saldo - ValorSaque;
    }else
    {
        fprintf(File, "Saque no valor de R$ %.2f negado devido a saldo insuficiente\n", ValorSaque);
        fclose(File);
        return Saldo;
    }
}
float Emprestimo(float Saldo, float ValorEmprestimo)
{
    FILE * File = fopen("out.txt", "a");
    fprintf(File, "Emprestimo realizado no valor de R$ %.2f\n", ValorEmprestimo);
    fclose(File);
    return Saldo + ValorEmprestimo;
}
void Extrato(float Saldo)
{
    char Str[100];
    FILE * File = fopen("out.txt", "r");
    while(fgets(Str, sizeof(Str), File))
    {
        printf("%s", Str);
    }
    fclose(File);
    printf("Saldo Atual: %.2f\n", Saldo);
}
#endif