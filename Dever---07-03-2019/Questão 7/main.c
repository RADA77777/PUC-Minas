#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int soma(float a, float b){
    printf("O resultado eh %f", a+b);
    return 0;
}
int subtracao(float a, float b){
    printf("O resultado eh %f\n", a-b);
    return 0;
}
int multiplicacao(float a, float b){
    printf("O resultado eh %f\n", a*b);
    return 0;
}
int divisao(float a, float b){
    printf("O resultado eh %f\n", a/b);
    return 0;
}
int main(){
    printf("Digite:\t1 para soma\n\t2 para subtracao\n\t3 para multiplicacao\n\t4 para divisao\n");
    int resposta;
    scanf("%i", &resposta);
    printf("Digite os dois valores:\n");
    float num1,num2;
    scanf("%f%f", &num1, &num2);

    if(resposta == 1){
        soma(num1,num2);
    }
    else if(resposta == 2){
        subtracao(num1,num2);
    }
    else if(resposta == 3){
        multiplicacao(num1,num2);
    }
    else if(resposta == 4){
        divisao(num1, num2);
    }
    return 0;
}
