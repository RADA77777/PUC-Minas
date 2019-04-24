#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define pass 0

int main() {
    int numero_Alunos = 0, idade_Velho = INT_MIN, idade_Novo = INT_MAX, idade_Atual, maiores = 0;

    do {

        printf("Digite a idade do aluno atual ou '0' para sair:\n");

        scanf("%d", &idade_Atual);

        if(idade_Atual == 0){
            printf("Obrigado por usar o programa!\n");
            continue;
        }

        if ( (idade_Atual < 1) || (idade_Atual > 100) ){

            printf("Idade inserida esta fora do dominio determinado[1-100] e sera desconsiderada!\n");
            continue;

        }


        idade_Atual < idade_Novo
        ? idade_Novo = idade_Atual
        : pass;


        idade_Atual > idade_Velho
        ? idade_Velho = idade_Atual
        : pass;


        idade_Atual >= 18
        ? maiores++
        : pass;


        numero_Alunos++;

    }while( idade_Atual != 0);


    printf("A idade do mais velho eh %d, a do mais novo eh %d, e a sala tem %.2lf%% de alunos maiores de idade!\n"
    , idade_Velho, idade_Novo, (double)maiores / numero_Alunos * 100);


    return 0;
}
