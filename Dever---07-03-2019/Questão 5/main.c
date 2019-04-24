#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(){
    int ano;
    bool AC=false;
    printf("Digite o ano:\n");


    scanf("%d", &ano);

    if(ano<0){
        AC=true;
    }

    if ((( ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0 ) && AC == false) {
        printf("O ano %d DC eh bissexto\n", ano);
    }

    else if((( ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0 ) && AC == true){
        printf("O ano %d AC eh bissexto\n", (ano * -1));
    }

    else{
        printf("O ano %d nao eh bissexto\n", ano);
    }
    return 0;
}
