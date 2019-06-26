#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main() {

    int mes;
    printf("Digite o numero do mes, de 1 a 12\n");
    scanf("%d", &mes);

    switch (mes){
        case 1: {
            printf("31 dias\n");
            break;
        }
        case 2: {
            printf("28 dias\n");
            break;
        }
        case 3: {
            printf("31 dias\n");
            break;
        }
        case 4: {
            printf("30 dias\n");
            break;
        }
        case 5: {
            printf("31 dias\n");
            break;
        }
        case 6: {
            printf("30 dias\n");
            break;
        }
        case 7: {
            printf("31 dias\n");
            break;
        }
        case 8: {
            printf("31 dias\n");
            break;
        }
        case 9: {
            printf("30 dias\n");
            break;
        }
        case 10: {
            printf("31 dias\n");
            break;
        }
        case 11: {
            printf("30 dias\n");
            break;
        }
        case 12: {
            printf("31 dias\n");
            break;
        }
        default: {
            printf("Digite um numero de 1 a 12\n");
        }
    }

    return 0;
}