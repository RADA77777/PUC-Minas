#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool _checar_se_iguais(float m1[10][10], float m2[10][10]);

void _check(int* colunas, int* linhas, int liminf, int limsup);

void _preencher_matriz(float m[10][10]);



int main()
{

    bool iguais = false;
    float m1[10][10], m2[10][10];

    printf("Preenchendo matriz 1...\n\n");
    _preencher_matriz(m1);


    printf("Preenchendo matriz 2...\n\n");
    _preencher_matriz(m2);


    iguais = _checar_se_iguais(m1,m2);


    if(iguais == true)
    {
        printf("As matrizes sao identicas\n\n");
    }
    
    else
    {
        printf("As matrizes sao diferentes\n\n");
    }

    return 0;
    
}




bool _checar_se_iguais(float m1[10][10], float m2[10][10])
{

    bool iguais = true;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(m1[i][j] != m2[i][j]) 
            {
                iguais = false; 

                /*
                
                Uma variavel de tipo bool eh declarada como true. Se, dentre os valores analisados, algum valor em m1[10][10] for
                diferente de um valor em m2[10][10], a variavel eh trocada para false, indicando que as matrizes
                m1[10][10] e m2[10][10] sao diferentes. Esse valor bool retornado influencia no if que eh encontrado em main() 
                
                */
            }
        }
    }

    return iguais;

}


void _check(int* colunas, int *linhas, int liminf, int limsup)
{

    while( (*colunas > limsup) || (*colunas < liminf) || (*linhas > limsup) || (*linhas < liminf) )
    {
        printf("Valores fora do escopo (1-10. Digite novamente o numero de colunas, depois o de linhas:\n\n");
        scanf("%d%d", colunas, linhas); //Garante que o numero de linhas e colunas esteja dentro do escopo
    }

}


void _preencher_matriz(float m[10][10])
{

    int colunas, linhas;


    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            m[i][j] = 0; //A matriz eh zerada para desconsiderar o lixo da memoria
        }
    }


    printf("Quantas colunas e linhas na matriz 1?: (1-10)\n");
    scanf("%d%d", &colunas, &linhas); //Obtido o numero de linhas e colunas

    _check(&colunas, &linhas, 1, 10); //Checado se os valores inseridos para M1 estao dentro do limite (1-10)
    


    for(int i = 0; i < colunas; i++)
    {
        for(int j = 0; j < linhas; j++)
        {
            printf("Digite um numero para armazenar em [%d] [%d]:\n", i, j);
            scanf("%f", &m[i][j]); //A matriz eh preenchida aqui, levando em conta os valores digitados para linhas e colunas
        }

    }

}