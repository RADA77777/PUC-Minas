#include <stdio.h>
#include <stdlib.h>

int main(){
    char input[30];
    int ano;
    char resposta;
    sim:

    printf("Digite o ano:\n");
    gets(input);
    ano= strtol(input, NULL , 0);
    fflush(stdin);


    (ano % 4 == 0 && ano % 100 != 0 ) || (ano % 400 == 0)
    ? printf("O ano %d eh bissexto\n", ano)
    : printf("O ano %d nao eh bissexto\n", ano);



    printf("Deseja testar de novo?\n");
    scanf("%c", &resposta);
    fflush(stdin);


    do{
        if(resposta == 's'){
            goto sim;
        }
        else if (resposta == 'n'){
            printf("Obrigado por usar!\n");
            break;
        }

        printf("Digite uma resposta valida ('s' ou 'n')\n");
        scanf("%c", &resposta);
        fflush(stdin);

    }while(1);

    return 0;
}