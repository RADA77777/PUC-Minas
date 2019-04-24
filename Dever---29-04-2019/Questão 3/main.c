#include <stdio.h>
#include <stdlib.h>

void escreverNumeros( int n, int limite);

float leReal();

int main(){
    
    printf("Digite o limite inferior e, depois, o superior:\n");

    int limiteInferior = leReal();
    int limiteSuperior = leReal();

    printf("Gerando a sequencia...\n\n");
    
    escreverNumeros(limiteInferior , limiteSuperior);

    return 0;
}


void escreverNumeros(int limiteInferior, int limiteSuperior){

    int n = limiteInferior;

    if( (n <= limiteSuperior) && (n >= limiteInferior) ){
        
        printf("%i\n", n);
        escreverNumeros( n + 1, limiteSuperior);
        printf("%i\n", n);

    }


    return ;
}

float leReal(){

    float real;
    scanf("%f", &real);
    
    return real;

}