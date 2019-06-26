#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int _ler_nota(float *notas, int i);

float _calcular_media(float *notas, int numero_alunos);

int _acima_media(float *notas, float media, int numero_alunos);

void _resultado(float media, int notas_acima_media);

int main()
{
	float *notas, media;
	int numero_alunos, notas_acima_media;

	notas = (float *)malloc(sizeof(float) );

	numero_alunos = _ler_nota(notas, 0);

	media = _calcular_media(notas, numero_alunos);

	notas_acima_media = _acima_media(notas, media, numero_alunos);

	_resultado(media, notas_acima_media);

	free(notas);
	return 0;
}

int _ler_nota(float *notas, int i)
{
	float nota;
	int flag = 0;

	printf("Digite uma nota, ou um valor negativo para sair:\n");
	scanf("%f", &nota);

	if(nota >= flag)
	{
		notas = (float *)realloc(notas, (sizeof(float) * (i + 1) ));
		notas[i] = nota;
		i++;
			
		i = _ler_nota(notas, i);
	}

	return i;
}

float _calcular_media(float *notas, int numero_alunos)
{
	float soma_total = 0, media;
	
	for(int i = 0; i < numero_alunos; i++)
	{
		soma_total += notas[i]; 
	}

	media = soma_total / numero_alunos;

	return media;
}

int _acima_media(float *notas, float media, int numero_alunos)
{
	int notas_acima_media = 0;

	for(int i = 0; i < numero_alunos; i++)
	{
		notas[i] > media
		? notas_acima_media++
		: 0;
	}

	return notas_acima_media;
}

void _resultado(float media, int notas_acima_media)
{
	 printf("A media das notas eh %f\n\n%i alunos obtiveram notas acima da media\n\n", media, notas_acima_media);
}