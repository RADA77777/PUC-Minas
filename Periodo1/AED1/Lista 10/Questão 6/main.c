#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool par( int numero);

/***************************************************************
 * Assinatura da função:   par
 * 
 * Data da elaboração:   10/04/2019
 * 
 * Autor:   Rafael Amauri Diniz Augusto
 * 
 * Objetivo:   Identificar se um número inteiro é par ou ímpar
 * 
 * Dados de entrada (argumentos):   Um número inteiro
 * 
 * Dado de saída (valor gerado pela função):   0
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

int main() {

    printf("Digite um numero:\n");    
    int numero = leReal();

    par(numero);


return 0;
}

bool par(int numero){
    
    bool par = false;

    if (numero % 2 == 0){
        par = true;
    }

    par == true
    ? printf("O numero %d eh par\n", numero)
    : printf("O numero %d eh impar\n", numero);
    
    return 0;
}


float leReal(){
    float real;
    scanf("%f", &real);

    return real;
}