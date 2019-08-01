#include <stdio.h>
#include <stdlib.h>

long long int exponencial(float base, int expoente);

float leReal();

int main() {

    printf("Digite uma base e, depois, um expoente:\n");

    float base = leReal();

    int expoente = leReal();

    printf("%lli\n\n",exponencial(base, expoente) );

    return 0;
}


long long int exponencial(float base, int expoente){

    long long int resultado = base;

    if( expoente > 1){

        resultado *= exponencial(base, expoente - 1);

    }

    return resultado;



}


float leReal(){

    float real;

    scanf("%f", &real);

    return real;
}