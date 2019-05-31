#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main() {

    int dia_da_semana;
    printf("Digite o numero do dia da semana, de 1 a 7\n");
    scanf("%d", &dia_da_semana);

    switch (dia_da_semana){
        case 1: {
            printf("Domingo\n");
            break;
        }
        case 2: {
            printf("Segunda\n");
            break;
        }
        case 3: {
            printf("Terca\n");
            break;
        }
        case 4: {
            printf("Quarta\n");
            break;
        }
        case 5: {
            printf("Quinta\n");
            break;
        }
        case 6: {
            printf("Sexta\n");
            break;
        }
        case 7: {
            printf("Sabado\n");
            break;
        }
        default: {
            printf("Digite um numero de 1 a 7\n");
        }
    }

    return 0;
}