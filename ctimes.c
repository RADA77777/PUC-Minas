#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define bool   short
#define true   1
#define false  0


struct Time
{
    char nome[100];
    char apelidos[100];
    char estadio[50];
    char tecnico[50];
    char membros[100];
    char liga[50];
    char nomeArquivo[50];

    int capacidade;
    int fundacaoDia, fundacaoMes, fundacaoAno;
   
    long int paginaTam; 
};

typedef struct Time Time;


Time* new_time(char nome[], char apelidos[], char estadio[], char tecnico[],
	       char membros[], char liga[], char nomeArquivo[], int capacidade, 
	       int fundacaoDia, int fundacaoMes, int fundacaoAno, long int paginaTam);



/*
 * Conjunto de funcoes usadas para achar as datas de fundacao dos times
 */

char* filtrarData(char string[]);

int* filtrarDia(char string[]);


/*
 * Retorna todos as palavras da string que estao entre as strings st1 e str2
 */

char* retornarEntreTags(char string[], char str1[], char str2[]);

/*
 * Recebe duas strings. Remove todas ocorrencias da segunda 
 * string na primeira e retorna a primeira
 */

char* removerCaracteres(char string[], char removidos[]);

/*
 * Recebe uma string e dois caracteres. Remove tudo que 
 * estiver entre tag1 e tag2 e retorna a string tratada
 */

char* removerTags(char string[], char tag1, char tag2);


/* 
 * Retorna um valor bool informando se
 * substring eh uma substring de string
 */
bool isSubstring(char string[], char substring[]);




int main(void)
{    
    FILE* arq;
    char *linha;
    char nomeArquivo[100];
    bool notFim = 1;

    linha = (char*)malloc(1000000 * sizeof(char));

   

    do
    {
	    //Pega o nome do arquivo do time
	    fgets(nomeArquivo, 50, stdin);
	    strtok(nomeArquivo, "\n");
	    notFim = strcmp(nomeArquivo, "FIM"); //Se a palavra nao for FIM, as maiusculas sao contadas e retornadas
            
	    if(notFim)
            {
		    arq = fopen("/home/rafael/Downloads/times/1._FC_Nurnberg.html", "r");
		    fscanf(arq, " %[^'\n']s",  linha);	

	            linha = (char*)malloc(100000* sizeof(char));
    
  		    // Ler a linha ate achar uma que comeca com <table. A que comeca com <table eh a com os dados
   		    while(linha != NULL)
		    {
			    free(linha);
			    linha = (char*)malloc(100000* sizeof(char));
			    fscanf(arq, " %[^'\n']s", linha);
			    
			    // Se a linha tiver a palavra <table nela, essa sera a linha com os atributos
			    if(isSubstring(linha, "infobox vcard"))
			    {
				    char nome[100], apelidos[100], data_fundacao[100], tecnico[100], estadio[100];
				    char capacidade[1000], data[100], liga[100];
		    			
				    strcpy(nome,     retornarEntreTags(linha, "Full name",    "Nickname(s)"));
				    strcpy(nome, removerTags(nome, '<', '>'));

				    strcpy(apelidos, retornarEntreTags(linha, "Nickname(s)",  "Founded"    ));
				    strcpy(apelidos, removerTags(apelidos, '<', '>'));

                    strcpy(estadio,  retornarEntreTags(linha, "Ground",       "</td>"   ));
				    strcpy(estadio, removerTags(estadio, '<', '>'));
				    
				    if(isSubstring(linha, "Head coach"))
				    	strcpy(tecnico,  retornarEntreTags(linha, "Head coach",   "</td>"     ));
				    
				    else
				    	strcpy(tecnico,  retornarEntreTags(linha, "Manager",      "</td>"     ));
				    
				    strcpy(tecnico, removerTags(tecnico, '<', '>'));

				    strcpy(liga, retornarEntreTags(linha, "League",       "</td>"      ));
				    strcpy(liga, removerTags(liga, '<', '>'));
				    
				   
				    strcpy(data,     retornarEntreTags(linha, "Founded",      "</td>"     ));
				    strcpy(data, removerTags(data, '<', '>'));
				    strcpy(data, removerTags(data, '&', ';'));
					strcpy(data, filtrarData(data));
			       
                /* DATA nao funciona
                 *
                 */    
				    int dia[3] = filtrarDia(data);
				    printf("%d = dia\n", dia[0]);
				    
				    printf("\nNome = %s\nApelidos = %s\nEstadio = %s\nTecnico = %s\nLiga = %s\nData = %s\n\n", nome, apelidos, estadio, tecnico, liga, data);
				    break;
		 	    }	    
		    }
	    }
    } while(notFim);
    return 0;
}

int* filtrarDia(char string[])
{
	// Salvar dois index: index1, index2. Usar strncpy pra cortar e armazenar em data[1] e data[2]

	int data[3];
	int* m = data;
	char aux[10];
 
	int index1, index2;
	for(int i = 0; i < strlen(string); i++)
		if(string[i] == '-')
		{	
			index1 = i+1;
			for(int j = i+1; j < strlen(string); j++)
				if(string[j] == '-')
		
					index2 = j;
					i = strlen(string);
		}
	
	strncpy(aux, string+index1, index2-index1);
	data[0] = atoi(aux);	
	
	strncpy(aux, string+index2+1, strlen(string)-index2);
	data[1] = atoi(aux);
	
	data[2] = atoi(strtok(string, "-"));

	return m;
}

char* filtrarData(char string[])
{
	
	char* dataFiltrada = retornarEntreTags(string, "(", ")");

	return dataFiltrada;
}

char* retornarEntreTags(char string[], char str1[], char str2[])
{

        bool isStr1 = false, isStr2 = false;
	char *stringEntreTags;
	stringEntreTags = (char*)malloc(10000 * sizeof(char));
	
        for(int i = 0; i < strlen(string); i++)
     	{ 
		if(string[i] == str1[0])
                {
                        isStr1 = true;
                        for(int j = 0; j < strlen(str1); j++)
			{
				if(string[i+j] != str1[j])
				{
					isStr1 = false;
				}
			}
		}	
		if(isStr1)
		{	
			for(int j = i; j < strlen(string); j++)
                         
				if(string[j] == str2[0])
				{
					isStr2 = true;
					for(int k = 0; k < strlen(str2); k++)
					{
						if(string[j+k] != str2[k])
						{			
							isStr2 = false;			
						}
					}
					
					if(isStr1 && isStr2)
					{
					strncpy(stringEntreTags, 
						string + i + strlen(str1),
						j - i - strlen(str1)
						);
					
					return stringEntreTags;
					}
				}

		}
	}
	return stringEntreTags;
}

char* removerCaracteres(char string[], char parteRemovida[])
{
	char* p = string;
	bool isParteRemovida;

	for(int i = 0; i < strlen(string); i++)
		 

		// Caso ache a primeira letra de parteRemovida, sera ativado um 
		// loop <for> para ver se aquela letra corresponde à parte a ser removida
		// ou se for apenas uma letra de outra palavra
		
		if(string[i] == parteRemovida[0])
		{
			isParteRemovida = true;
			for(int j = 0; j < strlen(parteRemovida); j++)	
				

				// Comparando com o resto da string. Se for diferente, a <isParteRemovida>
				// vira <false>, falhando no if que vem em seguida e voltando para o loop
				
				if(string[i+j] != parteRemovida[j])
					
					isParteRemovida = false;
			
			
			if(isParteRemovida)
			{	
				for(int j = i; j < strlen(string)-1; j++)
					
					string[j] = string[j+1];

				
				string[strlen(string) - 1] = '\0';
				i--;
			}	
		}
	return p;
}


char* removerTags(char string[], char tag1, char tag2)
{
	char* ponteiroString = string;
	char parte1[10000];
	char parte2[10000];
	memset(&parte1[0], '\0', sizeof(parte1));
	memset(&parte2[0], '\0', sizeof(parte2));

	for(int i = 0; i < strlen(string); i++)
		
		if(string[i] == tag2)

			for(int j = i; j >= 0; j--)
				
				if(string[j] == tag1)
				{
					
					memcpy(parte1, string, j);
					sprintf(parte2, "%s", string+i+1);
					// A string parte2 eh concatenada a parte1, por isso
					
					// parte1 vai virar a string completa depois da execucao da funcao
					strcat(parte1, parte2);
					
					ponteiroString = removerTags(parte1, tag1, tag2);
					i = strlen(string);
				}

	return ponteiroString;
}

bool isSubstring(char string[], char substring[])
{       
        bool isContido = false;

        for(int i = 0; i < strlen(string); i++)
               
                if(string[i] == substring[0])
		{
                        isContido = true;
                        for(int j = 0; j < strlen(substring); j++, i++)
                              
                                if(string[i] != substring[j])
                                {       
                                        
                                        j = strlen(substring);
                                        isContido = false;
                                }
                          
                        if(isContido == true)
                                i = strlen(string);
		}
        
        return isContido;
}


Time* new_time(char nome[], char apelidos[], char estadio[], char tecnico[], 
	       char membros[], char liga[], char nomeArquivo[], int capacidade, 
	       int fundacaoDia, int fundacaoMes, int fundacaoAno, long int paginaTam)

{ 
	Time* p = malloc(sizeof(Time));
  
	strcpy(p->nome,        nome    );
  	strcpy(p->apelidos,    apelidos);
  	strcpy(p->estadio,     estadio );
	strcpy(p->tecnico,     tecnico );
  	
	strcpy(p->membros,     membros    );
	strcpy(p->liga,        liga       );
	strcpy(p->nomeArquivo, nomeArquivo);

  	p->capacidade  = capacidade;
	p->fundacaoDia = fundacaoDia;
  	p->fundacaoMes = fundacaoMes;
 	p->fundacaoAno = fundacaoAno;
  	p->paginaTam   = paginaTam;
   	
	return p;
}

