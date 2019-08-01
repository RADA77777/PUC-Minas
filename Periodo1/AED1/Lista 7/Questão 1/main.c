#include <stdio.h>
#include <stdlib.h>
#define printf __mingw_printf


int main(){
    long double h=0;
    int base = 100, termos;

    printf("Digite quantos termos deseja calcular:\n");
    scanf("%d", &termos);

    for(int i = 0; i < termos; i++){
        h+= 1.0/base;
        base -= 3;
        printf("O %d valor de 'H' vale:  %Lf\n", i+1, h);
    }



    return 0;
}
