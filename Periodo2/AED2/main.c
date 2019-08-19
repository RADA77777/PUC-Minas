#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Time
{
    char nome[50];
    char apelido[50];
};


typedef struct Time Time;

// Construtor de time
Time* new_time(char nome[], char apelido[]);


int main(void)
{
    char nome[] = "Real Madrid";
    char apelido[] = "R.M.";
    char nomeArquivo[50];
    FILE *arq;
    
    //Pega o nome do arquivo do time
    fgets(nomeArquivo, 50, stdin);
    strtok(nomeArquivo, "\n");


    arq = fopen(nomeArquivo, "r");

    
    return 0;
}


Time* new_time(char nome[], char apelido[]) 
{ 
  Time* p = malloc(sizeof(Time));
  
  strcpy(p->nome, nome);
  strcpy(p->apelido, apelido);
  return p;
}