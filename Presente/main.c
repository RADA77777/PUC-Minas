#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() { 

int j, k;


//Parte de Cima do Coração
printf("\tFELIZ DIA DAS MÃES, MÃE!\n");

for(int i = 20; i >= 0; i-=6)
{
  for (k = 0; k < (i-6)/2 ; k++)
  {

    printf(" ");
  }

  for(j = 0; j < 20-i; j++)
  {
  printf("S");
  }


  for(int y = 0; y <= (20-k-j)*2; y++)
  {
    printf(" ");
  }
  

  for(int j = 0; j < 20-i; j++)
  {
  printf("S");
  
  }

  printf("\n");
}




//Parte do Meio do Coração
for(int i = 0; i < 3; i++){
for(int j = 0; j <= 40; j++)
  {
    printf("S");
  }
  printf("\n");
}



/*Parte de Baixo do Coracão*/
    for(int i = 40; i >= 0; i-=4)
    {
      
      for (int k = 0; k < (40-i)/2; k++)
        {
           printf(" ");
        }

      for(int j = i; j >= 0; j--)
      {
        printf("S");
      } 
      printf("\n");
    }  
  } 
