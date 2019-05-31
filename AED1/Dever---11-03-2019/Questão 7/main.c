#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    double altura, peso;
    printf("Digite sua altura em metros e, depois, seu peso:\n");
    scanf("%lf%lf", &altura, &peso);
    double imc = peso /pow(altura,2);

    if(imc < 16){
        printf("Magreza grave\n");
    }
    else if( (imc >= 16) && (imc < 17)){
        printf("Magreza moderada\n");
    }
    else if( (imc >= 17) && (imc < 18.5)){
        printf("Magreza leve\n");
    }
    else if( (imc >= 18.5) && (imc < 25)){
        printf("Saudavel\n");
    }
    else if( (imc >= 25) && (imc < 30)){
        printf("Sobrepeso\n");
    }
    else if( (imc >= 30) && (imc < 35)){
        printf("Obesidade Grau 1\n");
    }
    else if( (imc >= 35) && (imc < 40)){
        printf("Obesidade Grau 2 (severa)\n");
    }
    else{
        printf("Obesidade Grau 3 (morbida)\n");
    }

    return 0;
}