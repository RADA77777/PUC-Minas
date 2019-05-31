#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

#define pass 0

int main(){
	float producao = INT_MIN, defeitos = INT_MIN, producao_In, defeitos_In, flag;

	for( int i = 0; i < 500; i++){
	
		printf("Digite a quantidade de pecas produzidas, e depois a quantidade de peças defeituosas (Digite '0' em ambos para sair):\n");


		 do {
            /* Aqui eh checado se o valor de "numero" eh de fato um numero. Caso nao seja, sera acionada a
         * flag, e o loop ira se repetir */

            flag = 0;

            if( (scanf("%f", &producao_In) != 1) || (scanf("%f", &defeitos_In) != 1) || (producao_In != (int)producao_In) || (defeitos_In != (int) defeitos_In) ){
                printf("Por favor, digite dois numeros inteiros\n\n");
                flag = 1;
		__fpurge(stdin);
            }

        } while(flag == 1);

		if( (producao_In == 0) && (defeitos_In == 0) ){
			printf("Saindo..\n");
			break;
		}

		if( (producao_In < 0) || (defeitos_In < 0) ){
			printf("Nao sao aceitos valores negativos para numero de pecas\n\n");
			continue;
		
		}	

		producao_In > producao
		? producao = producao_In, defeitos = defeitos_In
		: pass;

	}	

	printf("A maquina com maior producao produziu %f items, e teve %f pecas defeituosas\n\n", producao, defeitos);

	return 0;

	
}
