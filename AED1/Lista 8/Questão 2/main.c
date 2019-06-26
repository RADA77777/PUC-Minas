#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int fatorial;
    long long int resultado;

    while(true){
        printf("Digite o numero que deseja saber o fatorial, ou, para sair, um numero negativo:\n");
        scanf("%d", &fatorial);

        
        if(fatorial < 0){
            break;
        }
        
        
        resultado = fatorial;

        
        for(int i = (fatorial -1); i > 1; i--){
            resultado *= i;
        }

        
        resultado == 0
        ? resultado = 1
        : 0;

        printf("O resultado eh %lli\n", resultado);

    }

    printf("Obrigado por usar!\n");
    
    return 0;

}