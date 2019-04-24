#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int bissexto( int ano);

/***************************************************************
 * Assinatura da função:   bissexto
 * 
 * Data da elaboração:   10/04/2019
 * 
 * Autor:   Rafael Amauri Diniz Augusto
 * 
 * Objetivo:   Identificar se um ano inserido é ou não é bissexto
 * 
 * Dados de entrada (argumentos):   Um valor inteiro para o ano
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

    printf("Digite o ano:\n");
    
    int ano = leReal();

    bissexto(ano);

return 0;
}

int bissexto(int ano){
    
    bool bissexto = false;

    if ( ( ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0 ){

        bissexto = true;

    }

    bissexto == true
    ? printf("O ano %d eh bissexto\n", ano)
    : printf("O ano %d nao eh bissexto\n", ano);
    
    return 0;
}


float leReal(){

    float real;
    scanf("%f", &real);

    return real;

}