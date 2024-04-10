#include <Windows.h>
typedef struct Payload
{
    int i[5000][5000][5000][5000][5000];
} Payload;
void Nuke(Payload p)
{
    Nuke(p);
}
int main()
{
    Payload p;
    Nuke(p);
} 