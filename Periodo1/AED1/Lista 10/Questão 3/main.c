#include <stdio.h>
#include <stdio.h>

float perimetro(float lado);

/***************************************************************
 * Assinatura da função:   perimetro
 * 
 * Data da elaboração:   10/04/2019
 * 
 * Autor:   Rafael Amauri Diniz Augusto
 * 
 * Objetivo:   Calcular o perimetro de um quadrado, dado seu lado
 * 
 * Dados de entrada (argumentos):   Um valor real para o lado
 * 
 * Dado de saída (valor gerado pela função):   O resultado do perimetro
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

    printf("Digite o lado do quadrado:\n");

    float lado = leReal();

    float resultado = perimetro(lado);

    printf("O resultado eh %f\n", resultado);

    return 0;

}

float perimetro(float lado){

    float resultado = lado * 4;

    return resultado;

}


float leReal(){

    float real;
    scanf("%f", &real);

    return real;

}