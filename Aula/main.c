#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>



int troca (int *a, int *b){

    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
    

    return 0;
}

int main(){

    int a = 1, b = 2;

    troca(&a, &b);

    printf("%d %d\n\n\n", a, b);

    return 0;
}