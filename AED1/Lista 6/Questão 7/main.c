#include <stdio.h>
#include <stdlib.h>

int main() {
    int cont = 0, cont2 = 0;
    char lista[1500];
    int numeros[1500];

    printf("Digite os 10 numeros:\n");

    for(int i=0; i<10; i++){
        scanf("%d", &numeros[i]);
    }


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == j) {
                continue;
            }
            if (numeros[j] < numeros[i]) {
                cont++;
                cont2++;
            }
        }
        if (cont == 9) {
            printf("O maior eh %d\n", numeros[i]);
        }
        if (cont2 == 0) {
            printf("O menor eh %d\n", numeros[i]);
        }
        cont = 0;
        cont2 = 0;


    }
return 0;
}
