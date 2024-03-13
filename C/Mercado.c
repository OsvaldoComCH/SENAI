#include <stdio.h>
typedef struct
{
    char Nome[16];
    float Preco;
} Produto;
int main()
{
    Produto Catalogo[3][4] = 
    {
        {{"Pao", 0.75},{"Mortadela", 3},{"Presunto", 5},{"Queijo", 2}},
        {{"Batata", 1.2},{"Tomate", 9.8},{"Alface", 1.75},{"Pepino", 6.3}},
        {{"Banana", 4.5},{"Maca", 12},{"Laranja", 3},{"Poncan", 4}}
    };
    
}