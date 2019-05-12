#include <stdio.h>
#include <stdlib.h> 


void _preencher(int numeros[]);

int _contar(int numeros[]);	

int main()
{
	
	int numeros[10], quantidade_pares; //É declarado um array com 10 inteiros

	_preencher(numeros); //nessa funcao, o array eh preenchido com numeros inteiros
	quantidade_pares = _contar(numeros);
	printf("temos %d pares\n", quantidade_pares);
	
}


void _preencher(int numeros[])
{
	int n;

	for(int i = 0; i < 10; i++)
	{
		
		printf("Digite um numero:\n");
		scanf("%d", &n);
		numeros[i] = n; //O loop iteira e a cada iteração o valor referente a "i" no array eh obtido do teclado e mudado
	}
}

int _contar(int numeros[])
{
	int quantidade_pares = 0;


	for(int i = 0; i < 10; i++)
	{

		if( (numeros[i] % 2 )== 0)
		{
		
			quantidade_pares++; //Sao lidos todos valores do array e contados quantos sao pares. A variavel quantidade conta quantos pares existem e eh retornada
		}
	}

	return quantidade_pares;
}