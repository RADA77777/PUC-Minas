#include <stdio.h>
#include <stdlib.h>

void escreverNumeros( int n);

int main(){
    
    escreverNumeros(10);

    return 0;
}


void escreverNumeros( int n){

    if( n > 0){
        escreverNumeros( n - 1);
        printf("%i\n", n);
    }

    return ;
}