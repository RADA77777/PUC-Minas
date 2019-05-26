#include <stdio.h>
#include <stdlib.h>

const int colunas, linhas;

float Maior_valor_acima_diagonal(float m[linhas][colunas])
{   
    float maior = m[0][1];

    for(int i = 0; i < (linhas - 1); i++)
    {
        for(int j = (i + 1); j < colunas; j++)
        {
            if(m[i][j] > maior)
            {
                maior = m[i][j];
            }
        }
    }

    return maior;
}