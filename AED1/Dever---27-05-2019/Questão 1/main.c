#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int colunas = 10, linhas = 10;

bool Esta_na_matriz(float m[linhas][colunas], float valor);


bool Esta_na_matriz(float m[linhas][colunas], float valor)
{   
    bool esta_na_matriz = false;
    
    for(int i = 0; i < linhas; i++)
    {   
        if(esta_na_matriz == false)
        {
            for(int j = 0; j < colunas; j++)
            {
                if(m[i][j] == valor)
                {
                    esta_na_matriz = true;
                }
            }
        }
    }
    
    return esta_na_matriz;
}