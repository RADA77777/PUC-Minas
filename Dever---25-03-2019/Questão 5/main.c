#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int numero, maior = INT_MIN, termos = 0, soma = 0;
    double media;


    while(numero != 0){
        printf("Digite um numero:\n");
        scanf("%d", &numero);

        if(numero > maior){
            maior = numero;
        }
        soma += numero;
        termos++;

    }

    media = (double)soma / (termos-1);

    printf("O maior numero eh %d, e a media dos numeros inseridos eh %lf\n", maior, media);
    
    return 0;
}
