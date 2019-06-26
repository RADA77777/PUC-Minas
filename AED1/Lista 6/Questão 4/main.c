#include <stdio.h>

int main(void) {
  int n;
  double media, soma_idades=0, idade_individual;
  printf("Digite o numero de alunos:\n");
  scanf("%d", &n);


  for(int i = 0; i < n; i++){
    printf("Digite a idade do %d aluno:\n", i+1);
    scanf("%lf", &idade_individual);

    soma_idades+=idade_individual;
  }
  printf("A media das idades eh %lf anos", soma_idades/n);
  
  return 0;
}