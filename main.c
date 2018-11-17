#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Tam 35
//Função que cria o plano de fundo através de uma matriz
char **planoFundo(int);
void imprimeMapa(char **, int /*, int posPacX, int posPacY, int pos*/);

int main()
{
    int pontos = 0; //inicializa a pontuação
    int pontosMax = 200; //inicializa pontuação máxima
    int vida = 3; //inicializa a vida
    int posPacX = 12; //posição inicial do pacman em relação ao eixo-x
    int posPacY = 8; //posição inicial do pacman em relação ao eixo-y
    int posFant1X = 18; //posição inicial do Fantasma1 em relação ao eixo-x
    int posFant1Y = 12; //posição inicial do Fantasma1 em relação ao eixo-y

    char **M; /*matriz que representa o mapa*/
    char cursor;

    printf("-----------------------PACMAN-----------------------");
    printf("\n\n");
    M = planoFundo(Tam);
    imprimeMapa(M,Tam);
    /*função obstáculo aqui*/
    printf("\n\n");

    //getchar();
    return 0;
}

char **planoFundo(int tam)
{
    int i, j;
    char **M;
    M = (char**)malloc(tam * sizeof(char *));   //aloca uma dimensão da matriz
    for(i=0; i<tam;i++)
    {
        M[i] = (char*) malloc(tam * sizeof(char)); //aloca uma dimensão da matriz
        for(j=0;j<tam;j++)
        {
            if(j<8)
                M[i][j] = ' ';
            else
                if(i == 0 || i == 28)
                    M[i][j] = 205;
                else
                    if(j==8 || j== tam -1)
                        M[i][j] = 186;
                    else
                        M[i][j] = '*';
            if(i>28)
                M[i][j] = ' ';
        }

    }
    M[0][8] = 201;
    M[0][tam-1] = 187;
    M[12][8]=2;
    M[28][8] = 200;
    M[28][tam-1] = 188;

    return M;
}

void imprimeMapa(char **M, int tam/*, int posPacX, int posPacY, int pos*/)
{
    int i,j;
    char p[6] = "PONTOS";
    //char pto[4];
    char vida[6] = "VIDAS";

    for(i=1;i<7;i++)
        M[0][i] = p[i-1];

    for(i=1;i<7;i++)
        M[15][i] = vida[i-1];

    /*M[2][1] = 'P';
    M[2][2] = 'O';
    M[2][3] = 'N';
    M[2][4] = 'T';
    M[2][5] = 'O';
    M[2][6] = 'S';*/
    for(i=0; i<tam;i++)
    {
        printf("\n");
        for(j=0;j<tam;j++)
            printf("%c ", M[i][j]);
    }
}
