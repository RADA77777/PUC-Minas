#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int colunas, linhas;

bool Primeira_linha_igual_ultima(float m[linhas][colunas])
{   
    bool igual = true;

    for(int i = 0; i < colunas; i++)
    {
        if(m[0][i] != m[linhas-1][i])
        {
            igual = false;
        }
    }

    return igual;
}