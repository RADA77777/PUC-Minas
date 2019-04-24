#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float maior_entre_dois(float x, float y);


/***************************************************************
 * Assinatura da função:   maior_entre_dois
 * 
 * Data da elaboração:   08/04/2019
 * 
 * Autor:   Rafael Amauri Diniz Augusto
 * 
 * Objetivo:   Calcular o maior entre dois valores fornecidos
 * 
 * Dados de entrada (argumentos):   Dois numeros reais
 * 
 * Dado de saída (valor gerado pela função):   O maior entre os dois reais inseridos, caso sejam diferentes. Se forem iguais,
 * retorna false
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



int main(void){

    float x, y;

    printf("Digite o primeiro numero:\n");
    
    x = leReal();

    printf("Digite o segundo numero:\n");
    y = leReal();

    float maior = maior_entre_dois( x, y);

    if(maior != false){
    
    printf("O maior entre os dois valores eh %f\n\n", maior);
    
    }


    return 0;

}


float maior_entre_dois(float x, float y){

    float maior;

    if( x > y){
        maior = x;
    }

    else if( y > x){
        maior = y;
    }

    else{
        maior = false;
    }

    return maior;
}

float leReal(){

    float real;
    scanf("%f", &real);

    return real;
}