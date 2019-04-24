#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define pass 0


int main(){
    int maior, menor, flag = 0, flag2=0, resposta;

    double numero; /* "numero" eh declarado como double para verificar se ele eh um numero inteiro
                    * ou nao quando o usuario der a entrada */

    do{
        maior = INT_MIN, menor = INT_MAX;
        printf("Digite quantos numeros quiser e 0 para parar a leitura. Nao serao aceitos numeros negativos!\n");



        printf("Digite um numero:\n");




        do {
            /* Aqui eh checado se o valor de "numero" eh de fato um inteiro positivo. Caso nao seja, sera acionada a
         * flag2, e o loop ira se repetir */

            flag2 = 0;
            fflush(stdin);


            if( (scanf("%lf", &numero) != 1) || (numero != (int)numero) || (numero < 0) ){
                printf("Por favor, digite um numero inteiro e positivo\n");
                flag2 = 1;
            }
        } while(flag2 == 1);



        do{




            if(numero == 0){
                /* Se o primeiro valor dado para "numero" for 0, eh retornado "nenhum valor informado", e
                 * o loop eh quebrado para que o usuario responda se quer testar de novo */

                printf("Nenhum valor informado\n");
                break;
            }


            /* Aqui eh testado se o numero inserido eh o menor de todos que foram
             * inseridos, bem como se eh o maior de todos inseridos */

            numero < menor
            ? menor = numero
            : pass;

            numero > maior
            ? maior = numero
            : pass;



            printf("Digite um numero:\n");


            do {
                /* Caso o primeiro valor de todos nao seja 0, o programa vai testar se a entrada
                 * eh a maior ou menor ja vista, e aqui sera pedido para o usuario digitar
                 * quaisquer outros numeros*/

                flag2 = 0;
                fflush(stdin);


                if( (scanf("%lf", &numero) != 1) || (numero != (int)numero) || (numero < 0) ){
                    printf("Por favor, digite um numero inteiro e positivo\n");
                    flag2 = 1;
                }
            } while(flag2 == 1);




            if(numero == 0){
                /* Esse bloco serve so para testar se o numero inserido antes eh ou nao eh 0.
                 * Caso seja, significa que o usuario quer sair do programa. Assim, eh retornado
                 * o valor da amplitude e o loop eh quebrado, para depois perguntar se o usuario
                 * quer testar de novo*/
                printf("\nA amplitude vale %d\n", (maior- menor));
                break;
            }

        } while (true);

        /* Aqui eh simplesmente perguntado se o usuario quer testar de novo, com novos numeros */
        printf("Deseja testar de novo?\nDigite 1 para \"Sim\" e 0 para \"Nao\"\n");
        fflush(stdin);
        scanf("%d", &resposta);

        while( (resposta != 1) && (resposta != 0) ){
            /* Esse bloco garante que as unicas respostas possiveis sejam 0 ou 1 */
            printf("Resposta invalida... por favor, digite 1 para \"Sim\" e 0 para \"Nao\"\n");
            fflush(stdin);
            scanf("%d", &resposta);
        }

    }while (resposta != flag);


    printf("Obrigado por usar! :)\n");
    return 0;

}