#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float lado1, lado2, lado3;
    printf("Digite os lados do triangulo:\n");
    scanf("%f%f%f",&lado1, &lado2, &lado3);
    if((lado1 <= 0) || (lado2 <= 0) || (lado3 <= 0)){
        printf("Nao eh um triangulo\n");
        return 0;
    }

    if((lado1 != lado2) && (lado1 != lado3) && (lado2 != lado3)){
        printf("O triangulo eh escaleno\n");
    }

    else if((lado1 == lado2 && lado1 != lado3) || (lado1 == lado3 && lado1 != lado2) || (lado2 == lado3 && lado2 != lado1)){
        printf("O triangulo eh isosceles");
    }

    else{
        printf("O triangulo eh equilatero");
    }
    return 0;
}
