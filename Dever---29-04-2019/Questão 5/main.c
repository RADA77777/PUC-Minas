#include <stdio.h>
#include <stdlib.h>

int somarNumeros( int n, int limite, int soma);

float leReal();

int main(){
    
    printf("Digite o limite inferior e, depois, o superior:\n");
    
    int limiteInferior = leReal();
    int limiteSuperior = leReal();

    printf("Gerando a sequencia...\n\n");

    int soma = somarNumeros(limiteInferior, limiteSuperior, 0);

    printf("A soma vale %i\n", soma);

    return 0;

}


int somarNumeros(int limiteInferior, int limiteSuperior, int soma){

    soma += limiteInferior;

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