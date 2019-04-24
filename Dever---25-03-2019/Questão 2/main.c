#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, parte1=1, parte2=100, inversor = 1;
    printf("Digite quantos valores devem ser calculados:\n");

    scanf("%d", &n);



    for(int i = 0; i < n; i++){
        double resultado = (double)parte1 / (double)parte2 ;

        parte1 += 1;
        parte2 -= 3;


        resultado = pow(resultado , inversor);

        inversor *= -1;

        printf("%lf\n", resultado);

    }


    return 0;
}
