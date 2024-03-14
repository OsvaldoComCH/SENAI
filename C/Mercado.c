#include <stdio.h>
typedef struct
{
    char Nome[16];
    float Preco;
    unsigned int Quantidade;
} Produto;
int main()
{
    unsigned int Setor, Prod, TempQtde;
    Produto Catalogo[3][4] = 
    {
        {{"Pao\0", 0.75, 0},{"Mortadela\0", 3, 0},{"Presunto\0", 5, 0},{"Queijo\0", 2, 0}},
        {{"Batata\0", 1.2, 0},{"Tomate\0", 9.8, 0},{"Alface\0", 1.75, 0},{"Pepino\0", 6.3, 0}},
        {{"Banana\0", 4.5, 0},{"Maca\0", 12, 0},{"Laranja\0", 3, 0},{"Poncan\0", 4, 0}}
    };
    printf("MERCADO\n1-Padaria\n2-Legumes\n3-Frutas\n");
    scanf("%i", &Setor);
    if(--Setor > 2){Setor = 2;}
    printf("%s\n", Setor ? (Setor==1 ? "Legumes" : "Frutas") : "Padaria");
    while(1)
    {
        for(int i = 0; i < 4; ++i)
        {
            printf("%i- %s %.2f reais\n", i+1, Catalogo[Setor][i].Nome, Catalogo[Setor][i].Preco);
        }
        printf("0-Sair\n");
        scanf("%i", &Prod);
        if(!Prod){break;}
        if(--Prod > 3){Prod = 3;}
        printf("Quantidade: ");
        scanf("%i", &TempQtde);
        Catalogo[Setor][Prod].Quantidade += TempQtde;
    }
    float Total = 0;
    FILE * File = fopen("./Nota.txt", "w");
    fprintf(File, "\nNota Fiscal\n\n");
    fprintf(File, "Produto\t Preco Un.\t Qtde\t Subtotal\n");
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(!Catalogo[i][j].Quantidade)
            {
                continue;
            }
            Total += Catalogo[i][j].Preco * Catalogo[i][j].Quantidade;
            fprintf(File, "%s\t%.2f\t%i\t%.2f\n", Catalogo[i][j].Nome, Catalogo[i][j].Preco,
            Catalogo[i][j].Quantidade, Catalogo[i][j].Preco * Catalogo[i][j].Quantidade);
        }
    }
    fprintf(File, "Total:\t\t\t\t\t%.2f", Total);
    fclose(File);
}