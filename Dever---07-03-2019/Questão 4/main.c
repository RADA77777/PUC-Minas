#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int homem(float altura){
    printf("O seu peso ideal eh aproximadamente %.4f kg\n", ((altura*72.7)-58));
    return 0;
}
int mulher(float altura){
    printf("O seu peso ideal eh aproximadamente %.4f kg\n", ((altura*62.1)-44.7));
    return 0;
}

int main()
{
    char genero;
    float altura;
    printf("Digite o genero:\n");
    scanf("%c", &genero);
    printf("Digite sua altura em metros\n");
    scanf("%f", &altura);

    if(((int)genero == 77) || ((int)genero == 109)){
        mulher(altura);
    }
    else if(((int)genero == 72) || ((int)genero == 104)){
        homem(altura);
    }
    return 0;
}

