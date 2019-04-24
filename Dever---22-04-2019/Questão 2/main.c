#include <stdio.h>
#include <stdlib.h>

float soma(float x, float y);

/***************************************************************
 * Assinatura da função:   soma
 * 
 * Data da elaboração:   08/04/2019
 * 
 * Autor:   Rafael Amauri Diniz Augusto
 * 
 * Objetivo:   Calcular a soma de dois valores fornecidos
 * 
 * Dados de entrada (argumentos):   Dois numeros reais
 * 
 * Dado de saída (valor gerado pela função):   O resultado da soma
 * 
 ****************************************************************
 */

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

int main(){

    float x, y, resultado;

    printf("Digite o 1 numero:\n");
    x = leReal();

    printf("Digite o 2 numero:\n");
    y = leReal();

    resultado = soma( x, y);

    printf("O resultado eh %f\n", resultado);

    return 0;
}

float soma(float x, float y){

    return (x + y);
    
}

float leReal(){
    float real;
    scanf("%f", &real);


    return real;
}