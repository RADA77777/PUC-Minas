#include <stdio.h>
#include <stdlib.h>

const int colunas, linhas;

float Soma_coluna(float m[linhas][colunas], int coluna)
{   
    float soma = 0;

    for(int i = 0; i < linhas; i++)
    {
        soma += m[i][coluna];
    }

    return soma;
}