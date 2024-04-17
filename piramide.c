#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// #include <windows.h>
//CRIAR PIRAMIDE
typedef signed char int8;//inteiro de 1 byte
int8** createPiram(int b){
    int8 **piramide = (int8**) malloc(b * sizeof(int8*));
    for(int8 i = 0; i < b; i++){
        piramide[i] = (int8*) malloc( (i+1) * sizeof(int8));
    }
     for(int8 l=0;l<b;l++){
       for(int8 c=0;c<=l;c++){
            piramide[l][c] = (int8) (rand()%100)+1;
       }
     }
    return piramide;
}
int8 ** createEmptyPiram(int b)
{
    int8 **piramide = (int8**) malloc(b * sizeof(int8*));
    for(int8 i = 0; i < b; i++){
        piramide[i] = (int8*) malloc( (i+1) * sizeof(int8));
    }
    return piramide;
}
//PRINTAR PIRAMIDE
void printPiram(int8 **pyramMove, int8 **pyram, int8 base, int8 height, int8 choice){
    switch (choice){
    case 1:
        for( int8 l = 0; l < height; l++){
        printf("\n\n");
            for(int8 s = 0; s<height-l; s++){
              printf("    ");
            }
            for( int8 c = 0; c <= l; c++){
                printf("%d      ",(int) pyram[l][c]);
            }
        }
        break;
    case 2:
        for( int8 l = 0; l < height; l++){
            printf("\n\n");
            for(int8 s = 0; s<height-l; s++){
              printf("    ");
            }
            for( int8 c = 0; c <= l; c++){
                if(pyramMove[l][c]==-1){
                  printf("\033[44m\033[30m %d \033[0m      ",(int) pyram[l][c]);
                } else{
                printf("%d      ",(int) pyram[l][c]);
                }
            }
        }
        break;
    }
}
//CONSEGUIR AS POSIÇÕES EM BINARIO
int8* binary(int i, int8 height){
    int8* bin = (int8*) malloc(height * sizeof(int8));
    for(int8 _ = height-1; _ >= 0; _--){
        if(!i){
            bin[_] = 0;
        }else{
            bin[_] = i % 2;
            i = (i/2);
        }
    }
    return bin;
}
//COPIAR PIRAMIDE ORIGINAL
void copyPiram(int8 **pyramOrig, int8 **pyramDest, int8 b){
    for(int8 lin = 0; lin < b; lin++){
        for(int8 col = 0; col < b; col++){
            pyramDest[lin][col] = pyramOrig[lin][col];
        }
    }
}
void freePiram(int8 **piram, int8 height){
    for(int8 i = 0; i < height; i++){
        free(piram[i]);
    }
    free(piram);
}
//MAIN
int main() {
    while(1){
        srand(time(NULL));
        int8 b;
        int score=0;
        long long times=0;
        char see;
        printf("\n\nInsira a base da piramide:");
        do{
            printf("\n>>>  ");
            scanf("%i",&b);
        } while(b<=0);
        int8 height = b, base = b;
        int8 **pyramid = createPiram(b);
        int8 **bestWay = createEmptyPiram(b);
        int8 **pyraMove = createEmptyPiram(b);
        copyPiram(pyramid, bestWay, b);
        printf("==================================================================================================================================================================================\n\n");
        printPiram(0, pyramid, base, height, 1);
        printf("\n\n\n==================================================================================================================================================================================");
        // Sleep(5000);
        //CALCULAR CAMINHOS POSSIVEIS
        for(int8 i = 0; i < height; i++){
            times += 1 << i; 
        }
        for(int v = 0; v <= times; v+=2){
            int result = 0;
            int walkPyram = 0;
            copyPiram(pyramid, pyraMove, b);
            int8 * bin = binary(v,height);

            for(int lin = 0; lin < height; lin++){
                result += pyramid[lin][walkPyram];
                pyraMove[lin][walkPyram] = -1;
                if(bin[lin]){
                    walkPyram+=1;
                }
            }
            free(bin);
            if(result>score){
                score = result;
                copyPiram(pyraMove, bestWay, b);
            }
            if(b<=10){
                printf("\033[2J\033[H");
                printPiram(pyraMove, pyramid, base, height, 2);
                printf("\n");
            }else if (b<=15){
                printf("\033[2J\033[H");
                float load = ((v*100)/times)+1;
                printf("Loading...\t [ %.2f%% ]",load);
            }
        }
        printf("\n\n\n==========================================================================================\n||\t\t\t\t\tMELHOR CAMINHO\t\t\t\t\t||\n==========================================================================================\n\n");
        printPiram(bestWay, pyramid , base, height, 2);
        printf("\n\n\n==========================================\n||\tPONTUACAO:\t%d\t\t||\n==========================================",score);
        printf("\n\n\ntimes: %lld",times/2-1);

        freePiram(pyramid,height);
        freePiram(pyraMove,height);
        freePiram(bestWay,height);

    }
    return 0;
}