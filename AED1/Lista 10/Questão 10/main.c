#include <stdio.h>
#include <stdlib.h>


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

float potencia(float base, float expoente);

/***************************************************************
 * Assinatura da função:   potencia
 * 
 * Data da elaboração:   14/04/2019
 * 
 * Autor:   Rafael Amauri Diniz Augusto
 * 
 * Objetivo:   Calcula um número elevado a outro
 * 
 * Dados de entrada (argumentos):   A base e, em seguida, o expoente
 * 
 * Dado de saída (valor gerado pela função):   O valor real do resultado da potenciação
 * 
 ****************************************************************
 */



int main(){
    
    printf("Digite a base e, em seguida, o expoente\n");
    float base = leReal(), expoente = leReal();


    printf("O resultado de %f elevado a %f vale %f", base, expoente, potencia(base, expoente));

    return 0;
}


float leReal(){

    float real;
    scanf("%f", &real);

    return real;
}


float potencia(float base, float expoente){

    float potencia = 1;

    for( int i = 0; i < expoente; i++){

        potencia *= base;

    }

    return potencia;
}