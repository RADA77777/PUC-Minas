#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void leArranjo(int array[]);

void ordena(int array[], int alcance);

void escreveArranjo(int array[]);


int main() {
    
    int A[] = {6, 5, 4, 3, 2, 1};
	int B[] = {3, 1, 6, 4, 2, 5};
	int C[6];
	leArranjo(C);  // Preenche todo o arranjo com valores lidos
	ordena(A, 5);   // Desloca o maior valor do arranjo para a última posição, n vezes, até ordenar
	ordena (B, 5);
	ordena (C, 5);
	escreveArranjo(A);   // Escreve na tela todo o arranjo
	escreveArranjo(B);
	escreveArranjo(C);
  	return 0;
}

void leArranjo(int array[]){

	int n;

	for(int i = 0; i < 6; i++){
		printf("Digite o %d numero:\n", i+1);
		scanf("%d", &n);
		array[i] = n; //Array eh preenchido aqui
	}

}

void ordena(int array[], int alcance){

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

void escreveArranjo(int array[]){

	for(int i = 0; i < 6; i++){

		printf("%d,", array[i]);

	}

	printf("\n");

}