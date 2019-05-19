#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void _fibbonacci_preencher(int *inteiros);


int main()
{
    int *numeros = (int *)malloc(sizeof(int) ); // Inicializado um head de memoria chamado numeros, para ser passado 
                                                // para a funcao __fibbonacci_preencher

    _fibbonacci_preencher(numeros);
    
    free(numeros);

    return 0;
}

void _fibbonacci_preencher(int *inteiros)
{
    int passado = 0, atual = 1, proximo, cont = 0;
    char resposta;

    do{
    
    inteiros[cont] = passado;

    
    proximo = atual + passado;
    passado = atual;
    atual = proximo; // Aqui sao calculados os proximos numeros da sequencia de fibonnaci, assim nos valores estao sempre "andando"
    cont++; // cont serve como referencia para quantos numeros temos no array
    
    
    
    inteiros = realloc(inteiros, sizeof(int) * (cont + 1) ); // Aumentado a quantidade de memoria disponivel



    printf("A sequencia ate agora eh [ ");

    for(int i = 0; i < cont; i++)
    {
        printf("%d, ", inteiros[i]);    //Aqui eh impressa a sequencia de numeros que temos ate agora
    }

    printf("]\n");

    printf("Deseja descobrir o proximo numero? (S/N)\n"); //Aqui eh perguntado se o usuario deseja continuar gerando a sequencia
    scanf("%c", &resposta);
    __fpurge(stdin);

    while( (toupper(resposta) != 'N') && (toupper(resposta) != 'S') ) //Esse bloco garante que a resposta sera sempre 's' ou 'n'
        {
            printf("Nao entendi... Por favor digite 's' ou 'n':\n");
            __fpurge(stdin);
            scanf("%c", &resposta);

        }

    }while(toupper(resposta) != 'N');


    
}