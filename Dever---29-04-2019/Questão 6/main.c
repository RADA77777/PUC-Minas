#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int somarNumeros( int n, int limite, int soma);

float leReal();

int main(){
    
    printf("Digite o limite superior:\n");
    
    int limiteSuperior = leReal();

    printf("Gerando a sequencia...\n\n");

    int soma = somarNumeros(1, limiteSuperior, 0);

    printf("A soma vale %i\n", soma);

    return 0;

}


int somarNumeros(int limiteInferior, int limiteSuperior, int soma){

    soma += pow(limiteInferior, 3);

    if( (limiteInferior < limiteSuperior) ){

        soma = somarNumeros( limiteInferior + 1, limiteSuperior, soma);

    }


    return soma;
}

float leReal(){

    float real;
    scanf("%f", &real);
    
    return real;

}