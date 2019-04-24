#include <stdio.h>
#include <stdlib.h>

int main(){
    int expoente;
    float base, resultado;

    printf("Digite a base:\n");
    scanf("%f", &base);

    do {
        printf("Digite o expoente:\n");
        scanf("%d", &expoente);
    } while(expoente < 0);

    resultado = base;

    for(int i=1; i < expoente; i++){
        resultado = resultado *  base;
    }

    printf("O resultado eh %f\n", resultado);

    return 0;

}