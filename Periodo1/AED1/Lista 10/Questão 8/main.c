#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float pesoIdeal(float altura);

/***************************************************************
 * Assinatura da função:   pesoIdeal
 * 
 * Data da elaboração:   14/04/2019
 * 
 * Autor:   Rafael Amauri Diniz Augusto
 * 
 * Objetivo:   Calcula o peso ideal de uma pessoa segundo a fórmula de IMC, usada pela OMS
 * 
 * Dados de entrada (argumentos):   Um valor real para a altura da pessoa
 * 
 * Dado de saída (valor gerado pela função):   Um valor real para seu peso ideal
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
    printf("Digite sua altura:\n");
    float altura = leReal();


    printf("Seu peso ideal eh %f\n",pesoIdeal(altura));

    return 0;
}


float leReal(){
    float real;
    scanf("%f", &real);

    return real;
}

float pesoIdeal(float altura){
    float pesoIdeal;

    pesoIdeal = 21.75 * (pow(altura, 2));

    return pesoIdeal;
}