#ifndef BINARY_H
#define BINARY_H
int NOT(int A)
{
    return ~A;
}
int AND(int A, int B)
{
    return A&B;
}
int OR(int A, int B)
{
    return A|B;
}
int XOR(int A, int B)
{
    return A^B;
}
int SHIFTL(int A, int B)
{
    return A<<B;
}
int SHIFTR(int A, int B)
{
    return A>>B;
}
int NAND(int A, int B)
{
    return ~(A&B);
}
int NOR(int A, int B)
{
    return ~(A|B);
}
int NXOR(int A, int B)
{
    return ~(A^B);
}
#endif
