#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

    
void _copiar_matriz(float m1[10][10], float m2[10][10]);

bool _check_se_maior(int dimensoes1, int dimensoes2);

void _check(int* colunas, int* linhas, int liminf, int limsup);

int _preencher_matriz(float m[10][10]);


int main()
{
    
    bool maior_que = false, igual;
    float m1[10][10], m2[10][10];
    int dimensoes1, dimensoes2;


    printf("Preenchendo matriz 1...\n");
    dimensoes1 = _preencher_matriz(m1); //Matriz 1 eh preenchida e suas dimensoes sao retornadas


    printf("Preenchendo matriz 2...\n");
    dimensoes2 = _preencher_matriz(m2); //Matriz 2 eh preenchida e suas dimensoes sao retornadas


    maior_que = _check_se_maior(dimensoes1, dimensoes2);
    /*

    Aqui eh avaliado se o tamanho da primeira matriz (numero de linhas * colunas) eh maior q o da segunda, pois 
    para que a primeira matriz caiba na segunda, eh necessario que seja menor
    
    */


    if(maior_que == true)
    {
        printf("Impossivel copiar -- A matriz 1 eh maior que a matriz 2\n"); //Aqui so eh garantido que M1 eh, de fato, menor que M2
    }

    else
    {
        _copiar_matriz(m1, m2); //Matriz eh copiada

        printf("A copia da matriz 1 para a matriz 2 foi um sucesso!\n\n");
    }
    
    return 0;
}




bool _check_se_maior(int dimensoes1, int dimensoes2)
{

    bool maior_que = false;


    if(dimensoes1 > dimensoes2)
    {

        maior_que = true; //Se M1 for maior que M2, eh retornado true, impossibilitando a continuaçaõ da main()

    } 

    return maior_que;
}



void _copiar_matriz(float m1[10][10], float m2[10][10])
{

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {

            m2[i][j] = m1[i][j]; //Copia simples, passando os valores de M1 para M2;

        }
    }


}


void _check(int* colunas, int *linhas, int liminf, int limsup)
{

    while( (*colunas > limsup) || (*colunas < liminf) || (*linhas > limsup) || (*linhas < liminf) )
    {
        printf("Valores fora do escopo (1-10. Digite novamente o numero de colunas, depois o de linhas:\n\n");
        scanf("%d%d", colunas, linhas); //Garante que o numero de linhas e colunas esteja dentro do escopo
    }

}


int _preencher_matriz(float m[10][10])
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
    return (colunas * linhas);
}