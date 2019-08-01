#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define pass 0

int main(){
    int numero_Alunos, idade_Velho = INT_MIN, idade_Novo = INT_MAX, idade_Atual, maiores = 0;

    printf("Digite o numero de alunos:\n");

    scanf("%d", &numero_Alunos);

    for(int i = 0; i < numero_Alunos; i++){

        printf("Digite a idade do aluno atual:\n");

        scanf("%d", &idade_Atual);


        while(idade_Atual < 1 || idade_Atual > 100){
            printf("Idade inserida esta fora do dominio determinado[1-100]! Digite a idade novamente:\n");
            scanf("%d", &idade_Atual);
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


    }



    printf("A idade do mais velho eh %d, a do mais novo eh %d, e a sala tem %.2lf%% de alunos maiores de idade!\n"
            , idade_Velho, idade_Novo, (double)maiores / numero_Alunos * 100);


    return 0;
}
