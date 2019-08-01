#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define pass 0

int primo(int numero);

/***************************************************************
 * Assinatura da função:   primo
 * 
 * Data da elaboração:   10/04/2019
 * 
 * Autor:   Rafael Amauri Diniz Augusto
 * 
 * Objetivo:   Identificar se um número inteiro é ou não é primo
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


int main(){


    printf("Digite o numero:\n");
    int numero = leReal();


    primo(numero);
    return 0;
}

int primo(int numero){

    bool primo = true;

    for(int i = 2; i < numero; i++){
        
        if( numero % i == 0){
            primo = false;
            break;
        }

    }


    primo == true
    ? printf("O numero %d eh primo\n", numero)
    : printf("O numero %d nao eh primo\n", numero);


    return 0;

}

float leReal(){

    float real;
    scanf("%f", &real);

    return real;
}