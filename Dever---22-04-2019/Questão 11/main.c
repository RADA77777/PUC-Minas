#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



float leReal();

/***************************************************************
 * Assinatura da função:   leReal
 * 
 * Data da elaboração:   08/04/2019
 * 
 * Autor:   Rafael Amauri Diniz Augusto
 * 
 * Objetivo:   Lê um número real da entrada
 * 
 * Dados de entrada (argumentos):   Nenhum
 * 
 * Dado de saída (valor gerado pela função):   O valor real lido
 * 
 ****************************************************************
 */


float Maior( float x, float y);

/***************************************************************
 * Assinatura da função:   Maior
 * 
 * Data da elaboração:   14/04/2019
 * 
 * Autor:   Rafael Amauri Diniz Augusto
 * 
 * Objetivo:   Decide o maior entre dois valores
 * 
 * Dados de entrada (argumentos):   Dois valores reais
 * 
 * Dado de saída (valor gerado pela função):   O maior valor real lido
 * 
 ****************************************************************
 */


int main(){

    int flag = 0;
    float numero, maior = INT_MIN;
    
    while(numero != flag){

        printf("Digite um numero:\n");
        numero = leReal();
        maior = Maior(numero, maior);
    
    }

    printf("O maior valor inserido foi %f\n\n", maior);

    return 0;
}


float leReal(){

    float real;
    scanf("%f", &real);

    return real;
}


float Maior(float x, float y){

    float maior;


    if( x >= y){

        maior = x;

    }
    
    else{

        maior = y;

    }



    return maior;

}