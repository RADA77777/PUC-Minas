#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

#define pass 0

int main(){
	float numero_Alunos, nota, numero_Aprovados = 0, numero_Reprovados = 0, soma_Aprovados = 0, soma_Reprovados = 0;
	int flag;


	while(true){
	

		do {

            		flag = 0;
			printf("Digite a nota ou '-1' para sair:\n\n");
            		if( scanf("%f", &nota) != 1){
             
			     	printf("Por favor, digite um valor numerico para a nota!\n\n");
        		        flag = 1;
				fflush(stdin);
            	
				}


			} while( flag == 1);




		if( nota == -1.0){
			printf("Saindo...\n\n");
			break;
		}

		if( nota < 0){
			printf("Nao sao aceitos valores negativos para notas!\n\n");
			continue;
		}
		
		if( nota > 100){
			printf("Nao sao aceitos valores maiores que 100 para a nota final!\n\n");
			continue;
		}
		

		numero_Alunos++;

		nota >= 60 
		? numero_Aprovados++, soma_Aprovados += nota
		: pass;

		nota < 60
                ? numero_Reprovados++, soma_Reprovados += nota
                : pass;


	}


	printf("A nota media dos alunos aprovados vale %f, e a nota media dos reprovados vale %f\n\n", (soma_Aprovados/numero_Aprovados), (soma_Reprovados/numero_Reprovados));
	
		return 0;
}
