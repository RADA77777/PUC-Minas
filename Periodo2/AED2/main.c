#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Time
{
    char nome[50];
    char apelido[50];
};

typedef struct Time Time;

// Construtor de time
Time* new_time(char nome[], char apelido[]);

void removerTags(char string[]);

// Acha substrings em uma string. Usado para achar a linha em que esta <table
bool isSubstring(char string[], char substring[])
{
	bool isContido = false;
	for(int i = 0; i < strlen(string); i++)
	{
		if(string[i] == substring[0])
		{
			isContido = true;
			for(int j = 0; j < strlen(substring); j++, i++)
			{
				if(string[i] != substring[j])
				{

					isContido = false;
					j         = strlen(substring);
				}
			}
			if(isContido == true)
				i = strlen(string);
		}
	}
	return isContido;
}

int main(void)
{
    char nome[]    = "Real Madrid";
    char apelido[] = "R.M.";
    char *linha;
    char nomeArquivo[50];
    FILE *arq;
    
    linha = (char*)malloc(1000000 * sizeof(char));

    /*
    
    //Pega o nome do arquivo do time
    fgets(nomeArquivo, 50, stdin);
    strtok(nomeArquivo, "\n");

    */

    char a[] = "<br>a";
    removerTags(a);


   /*
    arq = fopen("/home/1201679@PUCMINAS.NET/Downloads/times/1._FC_Nürnberg.html", "r");
    fscanf(arq, " %[^'\n']s",  linha);
    int i = 0;

    //Aqui acha a linha com <table
    while(linha != NULL)
    {
    	i++;
	free(linha);
	linha = (char*)calloc(100000, sizeof(char));
	fscanf(arq, " %[^'\n']s", linha);
	if(isSubstring(linha, "<table"))
	{
		printf("%s\n\n", linha);
		break;
	}
    }
*/
    return 0;
}

void* removerTags(char string[])
{
	char formatado[10000];
	char formatado2[10000];
	for(int i = 0; i < strlen(string); i++)
	{
		if(string[i] == '>')
			
		{
			for(int j = i; j >= 0; j--)
			{
				if(string[j] == '<')
				{
					memcpy(formatado, string, j);
					sprintf(formatado2, "%s", string+i+1);
					strcat(
							formatado,
							formatado2
							);
					
					removerTags(formatado);
				}
			}
			i = strlen(string);
		}
	}
	return ;
}

Time* new_time(char nome[], char apelido[]) 
{ 
  Time* p = malloc(sizeof(Time));
  
  strcpy(p->nome, nome);
  strcpy(p->apelido, apelido);

  return p;
}
