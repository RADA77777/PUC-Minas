#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num;
    printf("Digite o numero:\n");
    scanf("%d", &num);
    if( (num % 2) == 0){
	printf("O numero %d eh par\n", num);
    }
    else{
	printf("O numero %d nao eh par\n", num);
    }
    return 0;
}
