#include <stdio.h>
#include <stdlib.h>
#define pass 0


int main(){
    int resposta,  votos_Chapa1=0,  votos_Chapa2=0,  votos_Validos=0,  votos_Brancos=0,  votos_Nulos=0;

    float percentual;


    do {

        printf("Digite:\t0 para sair do programa\n\t1 para votar na chapa 1\n\t2 para votar na chapa 2"
               "\n\t3 para votar branco\n\t4 para votar nulo\n");


        scanf("%d", &resposta);

        resposta == 1
        ? votos_Chapa1++, votos_Validos++
        : pass;


        resposta == 2
        ? votos_Chapa2++, votos_Validos++
        : pass;


        resposta == 3
        ? votos_Brancos++
        : pass;

        resposta == 4
        ? votos_Nulos++
        : pass;

        (resposta != 0) && (resposta != 1) && (resposta != 2) && (resposta != 3) && (resposta != 4)
        ? printf("Digite um numero valido, por favor!\n\n")
        : pass;

    } while(resposta != 0 );

    printf("Obrigado por usar!\n");




    printf("Resultado:\t%d pessoas votaram nulo\n\t\t%d pessoas votaram branco\n\t\t%d pessoas votaram na chapa 1"
           "\n\t\t%d pessoas votaram na chapa 2\n\n", votos_Nulos, votos_Brancos, votos_Chapa1, votos_Chapa2);


    votos_Chapa1 == votos_Chapa2
    ? printf("As duas chapas tiverem o mesmo numero de votos! Empate!\n")
    : pass;


    if(votos_Chapa1 > votos_Chapa2){
        percentual = (float)votos_Chapa1 / votos_Validos;
        printf("A chapa 1 venceu com %.0f%% dos votos validos!\n", percentual*100);
    }

    else if(votos_Chapa2 > votos_Chapa1){
        percentual = (float)votos_Chapa2 / votos_Validos;
        printf("A chapa 2 venceu com %.0f%% dos votos validos!\n", percentual*100);
    }

    return 0;
}
