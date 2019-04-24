#include <stdio.h>
#include <stdlib.h>

int fibonacci( int posicao_atual, int posicao_limite, int anterior, int atual);

float leReal();

int main(){
    
    printf("Digite quantos termos da sequencia de fibonacci voce deseja ver:\n");
    
    int limiteSuperior = leReal();

    printf("Gerando a sequencia...\n\n");

    fibonacci(0, limiteSuperior, 0, 1);


    return 0;

}


int fibonacci(int posicao_atual, int posicao_limite, int anterior, int atual){


    if(posicao_atual < posicao_limite){


        posicao_atual += 1;

        printf("%d,  ", anterior);

        fibonacci(posicao_atual, posicao_limite, atual, (atual + anterior) );

    }


    return atual;
}

float leReal(){

    float real;
    scanf("%f", &real);
    
    return real;

}