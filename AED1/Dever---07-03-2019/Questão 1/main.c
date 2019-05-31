#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,y;
    printf("Digite os dois numeros:\n");
    scanf("%f%f", &x,&y);
    if(x>y){
        printf("O maior numero eh %f\n",x);
    }
    else if(y>x){
        printf("O maior numero eh %f\n",y);
    }
    else{
        printf("Os numeros sao iguais\n");
    }
    return 0;
}

