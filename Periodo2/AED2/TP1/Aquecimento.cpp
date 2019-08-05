#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	char linha[100];
	int quantMaiusculas = 0;
	bool notFim;
	do
	{
		scanf(" %[^\n]", linha); // Ler a linha ate o final
		
		notFim = strcmp(linha, "FIM"); //Se a palavra nao for FIM, as maiusculas sao contadas e retornadas
		if(notFim)
		{
			for(int i = 0; i < strlen(linha); i++)
			{
                        	// Aqui cada caractere da linha eh convertida para seu valor ASC2.
                        	// Se for maior que 65 (A) e menor que 90 (Z), a letra eh contada
                        	if((int)linha[i] >= 65 && (int)linha[i] <= 90)
                        	{
                                	quantMaiusculas++;
                        	}
                	}
			
			printf("%d\n", quantMaiusculas);
			quantMaiusculas = 0;
		}
	} while(notFim);
	
	return 0;
}
