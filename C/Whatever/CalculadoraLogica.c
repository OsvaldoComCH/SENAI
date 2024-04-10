#include <stdio.h>
int main()
{
    int N1, N2, Op;
    printf("Number: ");
    scanf("%i", &N1);
    
    printf("Operator:\n1-NOT\n2-AND\n3-OR\n4-XOR\n");
    scanf("%i", &Op);
    if(Op==1)
    {
        printf("~%i = %i\n", N1, ~N1);
        return 0;
    }
    printf("Second Number: ");
    scanf("%i", &N2);
    switch(Op)
    {
        default:
            printf("Invalid operator. Using AND instead.\n");
        case 2:
            printf("%i & %i = %i\n", N1, N2, N1 & N2);
        break;
        case 3:
            printf("%i | %i = %i\n", N1, N2, N1 | N2);
        break;
        case 4:
            printf("%i ^ %i = %i\n", N1, N2, N1 ^ N2);
        break;
    }
}