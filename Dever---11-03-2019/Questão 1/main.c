#include <stdio.h>
#include <stdlib.h>

int main(){

    double a, b, c;
    printf("Digite os 3 numeros\n");
    scanf("%lf%lf%lf", &a, &b, &c);

    if((a + b) < c){
        printf("A soma de A e B eh menor que C");
    }
    return 0;
}