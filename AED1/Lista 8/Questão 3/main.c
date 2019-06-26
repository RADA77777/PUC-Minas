#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int divisiveis = 0, flag = 0;
    double Primeiro_termo, razao, x, Numero_termos;
    char resposta;


    do {


/* Inicio de um loop do{} while() que eh parado de ser executado na condicao da variavel resposta
 * ser 'N' ou 'n'. A variavel divisiveis sempre vira 0 no (re)inicio do loop para que a quantidade
 * de numeros da P.A. divisiveis por X seja reiniciada*/


        fflush(stdin);
        divisiveis = 0;


        do {
            printf("Digite o numero de termos (alem do primeiro):\n");
            flag = 0;
            fflush(stdin);

            if( (scanf("%lf", &Numero_termos) != 1) || (Numero_termos != (int)Numero_termos) || (Numero_termos <= 0)){
                    printf("O valor do numero de termos nao eh valido! Digite um numero inteiro e maior que 0, por favor:\n");
                    flag = 1;

                    /* Caso a entrada seja um caractere que nao seja um numero, eh dada a flag para
                     * que o loop do{} while() seja repetido */

            }

        } while (flag == 1);



        /* A partir daqui, o principio eh o mesmo. Eh dado um requisito, e caso a entrada do usuario
         * nao atinja esse requisito, eh dada a flag para repetir o bloco ate ser dada uma entrada satisfatoria */
        do{
            printf("Digite o primeiro termo:\n");
            flag = 0;
            fflush(stdin);

            if( scanf("%lf", &Primeiro_termo) != 1){
                printf("O valor do primeiro termo nao eh valido! Digite um numero, por favor:\n");
                flag = 1;
            }
        } while (flag == 1);





        do {
            printf("Digite a razao:\n");
            flag = 0;
            fflush(stdin);

            if( scanf("%lf", &razao) != 1 || razao == 0){
                printf("O valor da razao nao eh valido! Digite um numero diferente de 0, por favor:\n");
                flag = 1;
            }
        } while (flag == 1);






        do {
            printf("Digite x:\n");
            flag = 0;
            fflush(stdin);

            if( scanf("%lf", &x) != 1 || x == 0) {
                printf("O valor de X nao eh valido! Digite um numero diferente de 0, por favor:\n");
                flag = 1;
            }

        } while (flag == 1);


        /* Como o primeiro termo nao conta como divisivel, o bloco for comeca com 1 e vai ate
         * a quantidade de termos dada como entrada. Caso aquele termo seja divisivel por
         * x, ele eh contado como um dos numeros divisiveis. A operacao funciona pq
         * uma P.A. segue a regra Numero(P) = base + (razao * p). O primeiro termo apos o numero-base
         * acaba sendo base + razao, o segundo termo sera base + razao * 2, e por ai...*/

        double Numero_analisado = Primeiro_termo;

        for (int i = 1; i <= Numero_termos; i++) {
            if (fmod(Numero_analisado + (i * razao), x) == 0) {
                divisiveis++;
            }

        }

        printf("%d Termos divisiveis!\n", divisiveis);

        //Aqui eh perguntado se o usuario quer testar de novo
        
        printf("Deseja testar de novo?\n");
        fflush(stdin);
        scanf("%c", &resposta);


        //Esse bloco eh rodado caso a resposta do usuario seja diferente de S/N, e roda ate 
        // que ele insira uma entrada valida
        
        while( (resposta != 's' && resposta != 'S') && (resposta != 'n' && resposta != 'N') ){
            printf("Valor invalido! Digite [S/s-N/n]:\n");
            fflush(stdin);
            scanf("%c", &resposta);
        }

    } while(resposta != 'n' && resposta != 'N');

    printf("Obrigado por usar! :)\n");

    return 0;

}