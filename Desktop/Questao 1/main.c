#include <stdio.h>
#include <stdlib.h>

int lerNum(FILE *numeros);


int main()

{
  FILE *numeros;

  numeros = fopen("numeros.txt", "r"); //Abre-se o arquivo numeros.txt, onde estao armazenados 500 numeros inteiros

  int quantidade_pares = lerNum(numeros);

  printf("No arquivo numeros.txt temos %d numeros pares\n\n", quantidade_pares);

  return 0;
}




int lerNum(FILE *numeros)
{

  int quantidade_pares = 0, numero;

  while( !feof(numeros)) //a funcao feof retorna 1 quando termina de ler o arquivo que recebe, ent !feof() vai retornar 0 quando terminar
  {

    fscanf(numeros, "%d", &numero); //Aqui se lê um numero do arquivo e armazena na variavel "numero"
    
    

    if( ((numero % 2) == 0))
    {
      quantidade_pares++; //Se o numero lido for par, a variavel quantidade_pares aumenta em 1, para depois ser retornada
    }

  }
  return quantidade_pares;

}

