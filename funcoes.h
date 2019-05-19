#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


float _leReal(){ //Le um valor real e retorna

    float real;
    scanf("%f", &real);
    
    return real;
}

int _Sgrau(){ //Resolve equacoes de 2 grau
    float a,b,c,delta,raiz1,raiz2,y,x;
    printf("Digite o A, o B, o C e o X da equacao:\n");
    scanf("%f%f%f%f", &a, &b, &c, &x);

    y=(a * pow(x,2)) + (b * x) + (c);

    delta=(pow(b,2)) - (4*a*c);

    raiz1= ( (-b) + sqrt(delta) ) / (2*a);
    raiz2= ( (-b) - sqrt(delta) ) / (2*a);

    printf("\nAs raizes da equacao sao %f e %f, e a solucao eh %f\n", raiz1, raiz2, y);
    return 0;
}


void _ordena(int array[], int alcance){ //Ordena elementos de um array qualquer em ordem crescente

    int maior_que = 0, aux;

    for(int i = 0; i < (alcance + 1); i++)
    {
        for( int j = 0; j < (alcance + 1); j++)
        {
            if(array[i] > array [j]){
                maior_que++;
            }
        } /* Aqui eh contado quantos numeros no array sao menores que array[i] */ 

        if(maior_que == alcance)
        {
            aux = array[alcance];
            array[alcance] = array[i];
            array[i] = aux; //trocadas as posicoes
            ordena(array, (alcance - 1)); /* Passado um metodo recursivo pra reordenar, dessa vez com o alcance(quantas casas
                                            o loop for irá caminhar) reduzido em 1, ja que foi definido o maior valor anterior.
                                            Funciona obtendo o maior valor, depois o 2 maior valor, o 3, e assim por diante
                                            ate o ultimo
                                          */
        
        }

        maior_que = 0;
    }


}