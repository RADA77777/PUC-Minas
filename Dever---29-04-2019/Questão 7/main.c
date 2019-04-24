#include <stdio.h>
#include <stdlib.h>

long long int fatorial(int n);

float leReal();

int main() {

    printf("Digite um numero que deseja saber o fatorial:\n");

    int n = leReal();

    printf("%lli\n\n",fatorial(n));

    return 0;
}


long long int fatorial(int n){

    long long int Fatorial = n;

    if(n > 1){

        Fatorial *= fatorial(n - 1);

    }

    return Fatorial;



}


float leReal(){

    float real;

    scanf("%f", &real);

    return real;
}