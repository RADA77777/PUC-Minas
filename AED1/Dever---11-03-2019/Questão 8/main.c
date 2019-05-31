#include <stdio.h>
#include <stdlib.h>

int main() {
    double peso;
    int codigo;
    printf("Digite seu peso na Terra, e o codigo do planeta\n");
    scanf("%lf%d",&peso, &codigo);
    switch(codigo){
        case 1: {
            printf("Seu peso em Mercurio eh %lf kg\n", (peso * 0.37));
            break;
        }
        case 2: {
            printf("Seu peso em Venus eh %lf kg\n", (peso * 0.88));
            break;
        }
        case 3: {
            printf("Seu peso em Marte eh %lf kg\n", (peso * 0.38));
            break;
        }
        case 4: {
            printf("Seu peso em Jupiter eh %lf kg\n", (peso * 2.64));
            break;
        }
        case 5: {
            printf("Seu peso em Saturno eh %lf kg\n", (peso * 1.15));
            break;
        }
        case 6: {
            printf("Seu peso em Urano eh %lf kg\n", (peso * 1.17));
            break;
        }
        default: {
            printf("Digite um codigo de planeta valido\n");
        }
    }

    return 0;
}