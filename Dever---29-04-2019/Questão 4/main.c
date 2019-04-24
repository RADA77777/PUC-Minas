#include <stdio.h>
#include <stdlib.h>

void escreverNumeros( int n);

float leReal();


int main(){

    printf("Digite um numero:\n");

    int n = leReal();

    printf("Gerando a sequencia...\n\n");


    escreverNumeros(n);


    return 0;
}


void escreverNumeros( int n){

    if( n >= 0){
        printf("%i\n", n);
        escreverNumeros( n - 1);
    }

    return ;
}


float leReal(){

    float real;

    scanf("%f", &real);

    return real;
}