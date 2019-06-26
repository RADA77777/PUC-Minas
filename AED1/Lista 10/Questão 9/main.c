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



long long int fatorial(int numero);

/***************************************************************
 * Assinatura da função:   fatorial
 * 
 * Data da elaboração:   14/04/2019
 * 
 * Autor:   Rafael Amauri Diniz Augusto
 * 
 * Objetivo:   Calcula o valor fatorial de um numero inteiro
 * 
 * Dados de entrada (argumentos):   Um numero inteiro
 * 
 * Dado de saída (valor gerado pela função):   O valor inteiro do fatorial do numero
 * 
 ****************************************************************
 */



int main(){
    printf("Digite um numero:\n");
    int numero = leReal();
    
    printf("O valor fatorial de %d eh %lld\n",numero, fatorial(numero));

    return 0;

}


float leReal(){

    float real;
    scanf("%f", &real);

    return real;

}

long long int fatorial( int numero){
    long long int fatorial = 1;
 
    for (int i = numero; i > 1; i--){
        fatorial *= i;
    }
    


    return fatorial;
}