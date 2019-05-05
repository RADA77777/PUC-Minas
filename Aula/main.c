#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>



int funcao (){

    int grau, resultado = 0, resposta = 0;
    printf("Digite o grau da funcao:\n");

    scanf("%d", &grau);

    int numeros[grau];
    

    for(int expoente = grau; expoente >= 0; expoente--)
    {

        printf("Digite o %d valor:\n", expoente + 1);
        scanf("%d", &numeros[expoente]);


        if(numeros[expoente] < 0)
        {
    
        resultado = pow(numeros[expoente], expoente) + resultado;
        printf("%d\n\n", resultado);
    
        }

        else
        {

        resultado = pow(numeros[expoente], expoente) - resultado;

        }
    }
    

    return resultado;
}

int main(){

    printf("%d", funcao());

    return 0;
}