#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade_eu, idade_mae, idade_pai;

    //Questões 1 e 2
    FILE *exemplo;

    exemplo = fopen("exemplo.dat", "w");

    fprintf(exemplo, "%d\n", 19);

    fclose(exemplo);


    //Questão 3
    exemplo = fopen("exemplo.dat", "a");

    fprintf(exemplo, "%d\n%d\n", 59, 63);

    fclose(exemplo);


    //Questão 4
    exemplo = fopen("exemplo.dat", "r");

    fscanf(exemplo, "%d %d %d", &idade_eu, &idade_mae, &idade_pai);

    printf("Minha idade é %d\nIdade da minha mae é %d\nIdade do meu pai é %d\n\n", idade_eu, idade_mae, idade_pai);

    fclose(exemplo);

    return 0;
