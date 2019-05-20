#include <stdio.h>
#include <stdlib.h>


void _check(int* colunas, int *linhas, int liminf, int limsup);

void _preencher_matriz(float m[10][10]);

float _primeiro_da_linha(float m[10][10], int linha);

int _linha_do_maior_numero(float m[10][10]);



int main()
{

    float m[10][10], primeiro_da_linha;
    int linha_do_maior_numero;


    _preencher_matriz(m);


    linha_do_maior_numero = _linha_do_maior_numero(m);
    primeiro_da_linha = _primeiro_da_linha(m, linha_do_maior_numero);


    printf("\nO primeiro numero da linha onde esta o maior numero eh %f\n\n", primeiro_da_linha);

    return 0;


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




int _linha_do_maior_numero(float m[10][10])
{
    float maior = m[0][0];
    int linha_do_maior_numero = 0;


    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(m[i][j] > maior)
            {
                maior = m[i][j];
                linha_do_maior_numero = i; // Nessa funcao eh achado o maior numero e em qual linha (i) ele esta, para que
                                           // o numero da linha seja retornado 
            }
        }
    }

    return linha_do_maior_numero;
}

float _primeiro_da_linha(float m[10][10], int linha)
{
    
    return m[linha][0]; //Dada o numero da linha, eh retornado o primeiro numero que ocupa a primeira posicao de dita linha

}