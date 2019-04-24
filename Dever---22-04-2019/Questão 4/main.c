#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float area(float raio);

/***************************************************************
 * Assinatura da função:  raio
 * 
 * Data da elaboração:   10/04/2019
 * 
 * Autor:   Rafael Amauri Diniz Augusto
 * 
 * Objetivo:   Calcular a área de um círculo, dado seu raio
 * 
 * Dados de entrada (argumentos):   Um valor real para o raio
 * 
 * Dado de saída (valor gerado pela função):   O resultado da área calculada
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

    printf("Digite o raio do circulo\n");
    float raio = leReal();

    float resultado = area(raio);

    printf("A area do circulo vale %f\n", resultado);
    return 0;

}

float area(float raio){
    
    float resultado = pow(raio, 2) * M_PI;
    return resultado;


}

float leReal(){
    float real;
    scanf("%f", &real);

    return real;
}