#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int colunas, linhas;

bool Primeira_linha_igual_diagonal(float m[linhas][colunas])
{   
    bool igual = true;

    for(int i = 0; i < colunas; i++)
    {
        if(m[0][i] != m[i][i])
        {
            igual = false;
        }
    }

    return igual;
}