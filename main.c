#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void leArranjo(int array[]);

void deslocaMaiorParaFinal(int array[]);

void escreveArranjo(int array[]);

int main() {
     	int A[] = {6, 5, 4, 3, 2, 1};
	int B[] = {3, 1, 6, 4, 2, 5};
	int C[6];
	leArranjo(C);  // Preenche todo o arranjo com valores lidos
	deslocaMaiorParaFinal(A);   // Desloca o maior valor do arranjo para a última posição
	deslocaMaiorParaFinal(B);
	deslocaMaiorParaFinal(C);
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
		array[i] = n;
	}

}

void deslocaMaiorParaFinal(int array[]){
	
	int maior = INT_MIN, aux, posicao;

	for(int i = 0; i < 6; i++){
		
		if(i > maior) maior = array[i], posicao = i;
	
	}
	
	aux = array[posicao];
	array[posicao] = array[5];
	array[5] = aux;

}

void escreveArranjo(int array[]){

	for(int i = 0; i < 6; i++){
	
		printf("%d,", array[i]);

	}

	printf("\n");

}
