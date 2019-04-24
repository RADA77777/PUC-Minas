#include <stdio.h>
#include <stdlib.h>


int main(){
    int termos, atual = 0, anterior = 0, novo = 1;

    printf("Quantos termos da sequencia deseja mostrar?\n");

    scanf("%d", &termos);

    for(int i =0; i < termos; i++){
        printf("%d\n", novo);


        anterior = atual;
        atual = novo;
        novo = anterior + atual;
        

    }


    return 0;
}
