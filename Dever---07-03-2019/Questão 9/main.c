#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(){

    float num1,num2,num3, meio;
    printf("Digite os 3 numeros\n");
    scanf("%f%f%f", &num1, &num2, &num3);
    float numeros[3]={num1,num2,num3};

    if( ( (numeros[0] > numeros[1]) && (numeros[0] < numeros[2])) || ((numeros[0] < numeros[1]) && (numeros[0] > numeros[2]))){
        meio=numeros[0];
    }
    else if( ( (numeros[1] > numeros[0]) && (numeros[1] < numeros[2])) || ((numeros[1] < numeros[0]) && (numeros[1] > numeros[2]))){
        meio=numeros[1];
    }
    else if( ( (numeros[2] > numeros[0]) && (numeros[2] < numeros[1])) || ((numeros[2] < numeros[0]) && (numeros[2] > numeros[1]))){
        meio=numeros[2];
    }
    printf("O numero do meio eh %f\n", meio);
    return 0;
}
