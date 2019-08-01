#include <stdio.h>
#include <stdlib.h>


void _check(int* colunas, int *linhas, int liminf, int limsup);

int _preencher_matriz(float m[10][10]);

float _media(float m[10][10], int dimensoes);

int _acima_da_media(float m[10][10], float media);



int main()
{
    int dimensoes, acima_da_media;
    float m[10][10], media;

    dimensoes = _preencher_matriz(m);

    media = _media(m, dimensoes);

    acima_da_media = _acima_da_media(m, media);

    printf("A media eh %f, e existem %d numeros acima dela\n\n", media, acima_da_media);

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


float _media(float m[10][10], int dimensoes)
{
    float soma = 0;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            soma += m[i][j]; 
        }
    }

    /*
    
    O numero de dimensoes eh o de coluna * linhas, logo, ele diz quantos elementos foram inseridos na matriz.
    Esse codigo soma todos elementos da matriz e retorna (soma / dimensoes), que equivale à media
    
    */

    return (soma / dimensoes);
}



int _acima_da_media(float m[10][10], float media)
{
    int acima_da_media = 0;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(m[i][j] > media)
            {
                acima_da_media++;
            }
        }

    }

    /*
    
    Com a media ja conhecida, esse codigo verifica quais valores estao acima dela, e aumenta em 1 a variavel 'acima_da_media' a
    partir de cada valor acima da media que eh encontrado. No final, retorna a variavel 'acima_da_media'

    */

    return acima_da_media;


}