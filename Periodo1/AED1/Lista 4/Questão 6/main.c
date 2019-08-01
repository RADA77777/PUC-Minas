#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(){
    float a,b,c,delta,raiz1,raiz2,y,x;
    printf("Digite o A, o B, o C e o X da equacao:\n");
    scanf("%f%f%f%f", &a, &b, &c, &x);

    y=(a * pow(x,2)) + (b * x) + (c);

    delta=(pow(b,2)) - (4*a*c);

    raiz1= ( (-b) + sqrt(delta) ) / (2*a);
    raiz2= ( (-b) - sqrt(delta) ) / (2*a);

    printf("\nAs raizes da equacao sao %f e %f, e a solucao eh %f\n", raiz1, raiz2, y);
}
