#include <stdio.h>

int main(void) {
  int n;
  double base, razao;
  printf("Digite quantos elementos na P.A.\n");

  scanf("%d", &n);

  printf("Digite a base, depois a razao da P.A.\n");
  scanf("%lf%lf", &base, &razao);

  double resultado = base;
  for(int i=0; i < n; i++){
    printf("O %d elemento eh %lf\n\n", i+1, resultado);
    resultado += razao;
  }




  return 0;
}