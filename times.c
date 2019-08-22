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

char* removerCaracteres(char string[], char removidos[]);
char* removerTags(char string[], char tag1, char tag2);

// Acha substrings em uma string. Usado para achar a linha em que esta <table
bool isSubstring(char string[], char substring[]);

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



   
    arq = fopen("/home/rafael/Downloads/htmltimes/1._FC_Nürnberg.html", "r");
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
		char* p = linha;
		p = removerCaracteres(p, "\"");
		p = removerTags(p, '<', '>');
		printf("%s\n\n", p);
		break;
	}
    }
    return 0;
}

char* removerCaracteres(char string[], char removidos[])
{
	char* p = string;
	bool isRemovido;

	for(int i = 0; i < strlen(string); i++)
	{
		if(string[i] == removidos[0])
		{
			isRemovido = true;
			for(int j = 0; j < strlen(removidos); j++)
			{
				if(string[i+j] != removidos[j])
				{
					isRemovido = false;
				}
			}
			if(isRemovido)
			{
				for(int j = i; j < strlen(string); j++)
				{
					string[j] = string[j+1];
				}
				string[strlen(string) - 1] = '\0';
				i--;
			}	
		}
	}
	return p;
}


char* removerTags(char string[], char tag1, char tag2)
{

	char* p = string;
	char formatado[10000];
	char formatado2[10000];
	for(int i = 0; i < strlen(string); i++)
	{
		if(string[i] == tag2)
		{
			for(int j = i; j >= 0; j--)
			{
				if(string[j] == tag1)
				{
					memcpy(formatado, string, j);
					sprintf(formatado2, "%s", string+i+1);
					strcat(
							formatado,
							formatado2
							);
					p = removerTags(formatado, tag1, tag2);
				}
			}
			i = strlen(string);
		}
	}
	return p;
}

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

/*
Time* new_time(char nome[], char apelido[])
{ 
  Time* p = malloc(sizeof(Time));
  
  strcpy(p->nome, nome);
  strcpy(p->apelido, apelido);

  return p;
}*/
