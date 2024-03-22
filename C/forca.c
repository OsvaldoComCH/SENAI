#include <stdio.h>
#include <Windows.h>
char Palavra[2][11] = {"radiologia", "----------"};
int CheckLetter(char Letter)
{
    for(int i = 0; i < 11; ++i)
    {
        if(Letter % 32 + 96)
        {
            Palavra[1][i] = Palavra[0][i];
        }
    }
}
int main()
{

}