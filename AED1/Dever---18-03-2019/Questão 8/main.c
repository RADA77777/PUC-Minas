#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int soma(float a, float b){
    printf("O resultado eh %f\n\n", a+b);
    return 0;
}
int subtracao(float a, float b){
    printf("O resultado eh %f\n\n", a-b);
    return 0;
}
int multiplicacao(float a, float b){
    printf("O resultado eh %f\n\n", a*b);
    return 0;
}
int divisao(float a, float b){
    printf("O resultado eh %f\n\n", a/b);
    return 0;
}

int main(){

    do {

        printf("Digite:\t1 para soma\n\t2 para subtracao\n\t3 para multiplicacao\n\t4 para divisao\n\t0 para sair\n");
        int resposta;
        scanf("%i", &resposta);

        if(resposta == 0){
            printf("Obrigado por usar este programa!\n");
            break;
        }

        printf("Digite os dois valores:\n");
        float num1, num2;
        scanf("%f%f", &num1, &num2);

        switch(resposta) {
            case 1: {
                soma(num1, num2);
                break;
            }
            case 2: {
                subtracao(num1, num2);
                break;
            }
            case 3: {
                multiplicacao(num1, num2);
                break;
            }
            case 4: {
                divisao(num1, num2);
                break;
            }
            default:{
                break;
            }
        }

    } while(true);

    return 0;
}
