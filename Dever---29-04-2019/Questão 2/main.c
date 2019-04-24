#include <stdio.h>
#include <stdlib.h>

void escreverNumeros( int n);

int main(){

    escreverNumeros(1);

    return 0;
}


void escreverNumeros(int n){


    if( n < 6){
        
        printf("%i\n", n);
        escreverNumeros( n + 1);
        printf("%i\n", n);

    }


    return ;
}
