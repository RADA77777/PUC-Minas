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

int* filtrarData(char dataString[]);


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
    char linhaExtra[10000];
    char linha[100000];
    char nomeArquivo[100];
    bool notFim = 1;
    long int tamPag;

   

    do
    {
	    tamPag = 0;
	    memset(nomeArquivo, '\0', sizeof(nomeArquivo));
	    //Pega o nome do arquivo do time
	    fgets(nomeArquivo, 100, stdin);
	    strtok(nomeArquivo, "\n");
	    notFim = strcmp(nomeArquivo, "FIM"); //Se a palavra nao for FIM, as maiusculas sao contadas e retornadas

	    if(notFim)
            {
		    
		    arq = fopen(nomeArquivo, "r");
		    
		    fseek(arq, 0, SEEK_END);
		    tamPag = ftell(arq);
		    fseek(arq, 0, SEEK_SET);
			
		    fscanf(arq, " %[^\n]",  linha);	
		    fgetc(arq);

	            memset(linha, '\0', sizeof(linha));
    
  		    // Ler a linha ate achar uma que comeca com <table. A que comeca com <table eh a com os dados
   		    while(!feof(arq))
		    {
			    memset(linha, '\0', sizeof(linha));
			    
			    fscanf(arq, " %[^\n]", linha);

			    // Se a linha tiver a palavra <table nela, essa sera a linha com os atributos
			    if(isSubstring(linha, "infobox vcard"))
			    {
					
				    memset(linhaExtra, '\0', sizeof(linhaExtra));

				    
				    while(!isSubstring(linha, "League"))
				    {
			    		fscanf(arq, " %[^\n]", linhaExtra);
					strcat(linha, linhaExtra);
				    }
				
				    char nome[1000], apelidos[1000], tecnico[100], estadio[100];
				    char capacidadeString[1000], data[200], liga[100];
		    		    int dia, mes, ano, capacidade;
				
				    
				    removerTags(linha, '<', '>');    	
			     	    strcpy(nome,     retornarEntreTags(linha, "Full name", "</td>"));
				    strcpy(nome,     removerTags( nome, '&', ';'));
				
				    strcpy(apelidos, retornarEntreTags(linha, "Nickname(s)", "</td>"));
                    		    strcpy(apelidos, removerTags(apelidos, '&', ';'));
				    
				    strcpy(estadio,  retornarEntreTags(linha, "Ground", "</td>"));
				    strcpy(estadio, removerTags(estadio, '&', ';'));

				    strcpy(capacidadeString, retornarEntreTags(linha, "Capacity", "&#91;")); 
				    strcpy(capacidadeString, removerTags(capacidadeString, '&', ';'));
				    strcpy(capacidadeString, removerCaracteres(capacidadeString, " "));
				    strcpy(capacidadeString, removerCaracteres(capacidadeString, "."));
				    strcpy(capacidadeString, removerCaracteres(capacidadeString, ","));
				    capacidade = atoi(capacidadeString);
				
				    if(isSubstring(linha, "Coach"))
					strcpy(tecnico, retornarEntreTags(linha, "Coach", "</td"));
					
				    else if(isSubstring(linha, "Head coach"))
				    	strcpy(tecnico,  retornarEntreTags(linha, "Head coach", "</td>"));
				    
				    else if(isSubstring(linha, "Manager"))
				    	strcpy(tecnico,  retornarEntreTags(linha, "Manager", "</td>"));
				  
					
				    strcpy(tecnico, removerTags(tecnico, '&', ';'));

				    strcpy(liga, retornarEntreTags(linha, "League", "</td>"));
				    strcpy(liga, removerTags(liga, '&', ';'));
				   


				   //Pegar tudo entre Founded e &#59 (dia) e &#59 e &#160 (mes e ano)
				    strcpy(data, retornarEntreTags(linha, "Founde", "</td>"));
				   	
				    int* dias = filtrarData(data);
				    char dataStr[3][4];
				    char aux[80] = {"0"};
				    for(int i = 0; i < 3; i++)
				    {
					sprintf(dataStr[i], "%d", dias[i]);
					if(strlen(dataStr[i]) == 1)
					{
						strcat(aux, dataStr[i]);
						strcpy(dataStr[i], aux);
						strcpy(aux, "0");
					}
				           	
				    }

				    printf("%s ## %s ## %s/%s/%s ## %s ## %d ## %s ## %s ## %s ## %ld ##\n", nome, apelidos, dataStr[0], dataStr[1], dataStr[2], estadio, capacidade, tecnico, liga, nomeArquivo, tamPag);
					break;
		 	    }		    
		    }
		    fclose(arq);
	    }
    } while(notFim);
    return 0;
}



int* filtrarData(char dataString[])
{
	// Salvar dois index: index1, index2. Usar strncpy pra cortar e armazenar em data[1] e data[2]

	/*
	* data[0] eh o dia
	* data[1] eh o mes
	* data[2] eh o ano
	*/
	int data[3]; 
	int* ponteiroData = data;
	char numeroChar[1000];


	if(isSubstring(dataString, "&#32"))
	{
	
		strcpy(dataString, retornarEntreTags(dataString, "d", "&#32;"));
		strcpy(dataString, removerTags(dataString, '#', ';'));
		strcpy(dataString, removerCaracteres(dataString, ","));
			
		for(int i = 0; i < strlen(dataString); i++)
			if(dataString[i] == '&')
				dataString[i] = ' ';
	    

		dataString[strlen(dataString)-1] = '\0';
	}
	
	
	strcpy(dataString, removerCaracteres(dataString, ","));
	strcpy(dataString, removerCaracteres(dataString, "d"));
	
	if(strlen(dataString) == 4)
	{
		data[0] = 0;
		data[1] = 0;
		data[2] = atoi(dataString);
		return ponteiroData;
	}


	int index1 = -1, index2 = -1;
	for(int i = 0; i < strlen(dataString); i++)
		if(dataString[i] == '-' || dataString[i] == '/' || dataString[i] == ' ')
		{
			index1 = i;
			for(int j = i+1; j < strlen(dataString); j++)
				if(dataString[j] == '-' || dataString[j] == '/' || dataString[j] == ' ')
				{
					index2 = j;
					j = strlen(dataString);
					i = strlen(dataString);
				}	
		}	

		memset(numeroChar, '\0', sizeof(numeroChar)); // Zerando a string para impedir concatenacoes erradas
		// String antes do primeiro -
		
		strncpy(
			numeroChar,
			dataString,
			index1+1  //NAO DELETAR O + 1 PELAMOR DE DEUS SENAO VAI VOLTAR A DAR SEGMENTATION FAULT NA DATA E EU TO LOUCO JA 
			);
		
		data[0] = atoi(numeroChar);
		memset(numeroChar, '\0', sizeof(numeroChar)); // Zerando a string para impedir concatenacoes erradas


		// String entre as duas tags -
		strncpy(
			numeroChar,
			dataString + index1 + 1,
			index2 - index1
			);

		data[1] = atoi(numeroChar);
		memset(numeroChar, '\0', sizeof(numeroChar));


		// String depois do segundo -
		strncpy(
			numeroChar,
			dataString + index2 + 1,
			strlen(dataString) - index2
			);

		data[2] = atoi(numeroChar);
		memset(numeroChar, '\0', sizeof(numeroChar));

		


	/* Aqui confirmaremos que a data esta no formato dia/mes/ano.
	* A variavel <dataString> vai conter todo o conteudo que que esta entre "Founded" e "</td"
	* A logica eh ver se nomes de meses sao substrings de <numeroChar>
	* Se for, eh pq o mes que eh substring deve ser o valor numerico da variavel <data[1]>.
	* Caso o valor numerico de <mes> seja diferente do valor do mes no mundo real, ele
	* eh trocado com a variavel dia (Ex: <data[1]> = 3 e  subString(linha, "September") retorna True. Isso
	* nao pode acontecer, pois setembro eh o mes 9. Entao, concluimos que 3 so pode ser o dia! <data[0]> assume o valor
	* de <data[1]>, e <data[1]> vira 9)
	*/




	// Matriz com meses
	char meses[12][12] = {
				{"January"}, {"February"}, {"March"}, {"April"}, {"May"}, {"June"},
				{"July"}, {"August"}, {"September"}, {"October"}, {"November"}, {"December"}
			     };


	for(int i = 0; i < 12; i++)

		if(isSubstring(dataString, meses[i]) && data[1] != i+1)
		{
			if(data[0] == i+1 && data[1] != 0)
			{	
				data[0] = data[1];
				data[1] = i+1;
			}
			else
			{
				data[1] = i+1;
			}
		}


	return ponteiroData;
}


char* retornarEntreTags(char string[], char str1[], char str2[])
{

        bool isStr1 = false, isStr2 = false;
	char *stringEntreTags = (char*)malloc(10000 * sizeof(char));
	
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
					
						if(isSubstring(stringEntreTags, "ago") && str1 == "(" && str2 == ")")
						{
							memset(stringEntreTags, '\0', sizeof(stringEntreTags));
							continue;
						}
						else
						{	
						return stringEntreTags;
						}
					}
				}

		}
	}
	if(!isStr1 && !isStr2)
	{
		strcpy(stringEntreTags, string);
		return stringEntreTags;
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

	for(int i = 0; i < strlen(string); i++)
	{	 
		if(string[i] == '<' &&
                   string[i+1] == '/' &&
                   string[i+2] == 't' &&
                   string[i+3] == 'd' &&
                   string[i+4] == '>')
                   {
                        continue;
                   }
		if(string[i] == tag1)
		{
			for(int j = i; j < strlen(string); j++)
				
				if(string[j] == tag2)
				{
					
					for(int k = 0; k < j-i+1; k++)
					{
						for(int x = i; x < strlen(string)-1; x++)
						{
							string[x] = string[x+1];
						}
					string[strlen(string)-1] = '\0';
					}
					
					i--;
					j = strlen(string);	
				}
		}
	}
	ponteiroString = string;	
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

