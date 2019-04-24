#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(){

    float num1,num2,num3, maior;
    printf("Digite os 3 numeros\n");
    scanf("%f%f%f", &num1, &num2, &num3);
    float numeros[3]={num1,num2,num3};

    for(int i=0; i<3; i++){
        if(maior < numeros[i]){
            maior=numeros[i];
        }
    }
    printf("O maior numero eh %f", maior);
    return 0;
}
