#include <stdio.h>
#include <stdlib.h>

void _ler_notas(FILE *notas, int *numero_alunos);

float _media(FILE *notas, int numero_alunos);

void _resultado(float media, int notas_acima_media);

int _acima_da_media(FILE *notas, float media, int numero_alunos);


int main()

{
    float nota, media;
    int numero_alunos = 0, notas_acima_media;
    FILE *notas;


    notas = fopen("notas.txt","w");


    _ler_notas(notas, &numero_alunos);
    fclose(notas);


    notas = fopen("notas.txt", "r");


    media = _media(notas, numero_alunos);
    
    rewind(notas);

    notas_acima_media = _acima_da_media(notas, media, numero_alunos);

    

    _resultado(media, notas_acima_media);

    fclose(notas);

    return 0;
}



void _ler_notas(FILE *notas, int *numero_alunos)
{
  float nota, flag = 0;

  do
    {
      printf("Digite a nota do aluno ou um valor negativo para sair:\n");
      scanf("%f", &nota);

      if(nota >= flag)
        {
        fprintf(notas, "%f\n", nota);
        *numero_alunos += 1;
        }

    }while(nota >= 0);

}





float _media(FILE *notas, int numero_alunos)
{

  float soma_notas = 0, nota;

     for(int i = 0; i < numero_alunos; i++)
      {
        fscanf(notas, "%f", &nota);
        soma_notas += nota;
      }
    
    return (soma_notas/numero_alunos);
    
}





int _acima_da_media(FILE *notas, float media, int numero_alunos)
{
    float nota; 
    int notas_acima_media = 0;

    for(int i = 0; i < numero_alunos; i++)
    {

        fscanf(notas, "%f", &nota);

        nota > media
        ? notas_acima_media++
        : 0;

    }  

    return notas_acima_media;

}





void _resultado(float media, int notas_acima_media)
{

  printf("A media das notas eh %f\n\n%d alunos obtiveram notas acima da media\n\n", media, notas_acima_media);

}