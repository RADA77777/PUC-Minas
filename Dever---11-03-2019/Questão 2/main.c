#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {

    int a, b, c, contador, menor, meio, maior;
    printf("Digite os 3 numeros:\n");
    scanf("%d%d%d", &a, &b, &c);
    int numeros[3] = {a, b, c};

    for (int i = 0; i < 3; i++) {
        contador=0;
        for (int j = 0; j < 3; j++) {

            if (i == j) {
                continue;
            }
            if (numeros[i] < numeros[j]) {
                contador++;
            }
        }

        if (contador == 2) {
            menor = numeros[i];
        }

        else if (contador == 1) {
            meio = numeros[i];
            }

        else if (contador == 0) {
            maior = numeros[i];
        }
    }
    printf("O menor eh %d, o do meio eh %d, o maior eh %d\n", menor, meio, maior);
    return 0;
}