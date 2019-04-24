#include <stdio.h>

int main(void) {
  int lim_inf, lim_sup;
  printf("Digite o limite inferior, depois o superior:\n");
  scanf("%d%d", &lim_inf, &lim_sup);
  
  
  for(int i = lim_inf; i <= lim_sup; i++){
    printf("%d\n", i);
  }

return 0;

}