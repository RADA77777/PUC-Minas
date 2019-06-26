#include <stdio.h>
#include <stdlib.h>

int _quantas_vezes(float m[10][10], float valor);

void _check(int* colunas, int *linhas, int liminf, int limsup);

void _preencher_matriz(float m[10][10]);

int main()
{
    float m[10][10], valor;
    int quantas_vezes;

    printf("Preenchendo matriz...\n");
    _preencher_matriz(m);



    printf("Digite um valor que deseja pesquisar:\n\n");
    scanf("%f", &valor);


    quantas_vezes = _quantas_vezes(m, valor);

    printf("O valor '%.f' aparece %d vezes na matriz\n\n", valor, quantas_vezes);

    return 0;

}

int _quantas_vezes(float m[10][10], float valor)
{
    int quantas_vezes = 0;


    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j <10; j++)
        {
            if(m[i][j] == valor)
            {
                quantas_vezes++;
            }
        }
    }
 
 /*
 
    Esse loop for percore a matriz inteira procurando por um valor que foi parametrizado. A cada vez que eh encontrado,
    aumenta em 1 o valor da variavel 'quantas_vezes' 
 
 */

    return quantas_vezes;
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