#include <stdio.h>
#include <stdlib.h>



int main(){
    double numero1, numero2, resultado;
    int flag = 0;


    printf("Digite o primeiro numero:\n");

        do {
            /* Aqui eh checado se o valor de "numero" eh de fato um numero. Caso nao seja, sera acionada a
         * flag, e o loop ira se repetir */

            flag = 0;
            fflush(stdin);

            if( (scanf("%lf", &numero1) != 1) ){
                printf("Por favor, digite um numero\n");
                flag = 1;
            }

        } while(flag == 1);



    printf("Digite o segundo numero:\n");

            do {

                /* Mesmo principio de antes. Esse bloco apenas checa se o valor inserido
                 * eh, de fato, um numero*/

                flag = 0;
                fflush(stdin);


                if( (scanf("%lf", &numero2) != 1)){
                    printf("Por favor, digite um numero\n");
                    flag = 1;
                }

            } while(flag == 1);



       for(int i = 0; i < 100; i++){


           if( (i % 2) == 0){
                // Se [i] for positivo em A[i], faça A[i] - A[i-1] para obter A[i+1]
               resultado = numero2 - numero1;

           }

           else {
                // Se [i], for negativo, faça A[i] + A[i-1] para obter A[i+1]
               resultado = numero2 + numero1;

           }

            printf("O %d valor da sequencia vale %lf\n\n\n", (i+1), resultado);
            numero1 = numero2;
            numero2 = resultado;


       }



    printf("Obrigado por usar! :)\n");
    return 0;

}