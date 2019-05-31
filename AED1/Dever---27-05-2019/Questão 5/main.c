#include <stdio.h>
#include <stdlib.h>

const int colunas, linhas;

float Maior_valor_acima_diagonal(float m[linhas][colunas])
{   
    float maior = m[0][1];

    for(int i = 0; i < linhas; i++)
    {
        for(int j = (linhas + 1); i < (colunas); i++)
        {
            if(m[i][j] > maior)
            {
                maior = m[i][j];
            }
        }
    }

    return maior;
}

float Maior_valor_abaixo_diagonal(float m[linhas][colunas])
{   
    float maior = m[linhas-1][0];

    for(int i = 0; i < colunas; i++)
    {
        for(int j = (i + 1); j < linhas; j++)
        {
            if(m[j][i] > maior)
            {
                maior = m[j][i];
            }
        }
    }

    return maior;
}

float Diferenca(float valor1, float valor2)
{
    return (valor1 - valor2);
}