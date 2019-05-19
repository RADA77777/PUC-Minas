#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int _quantidade_numeros_negativos(int numeros[], int tamanho);

int _inserir_numeros(int numeros[]);



int main()
{

    int numeros[100], negativos, tamanho;

    tamanho = _inserir_numeros(numeros);

    negativos = _quantidade_numeros_negativos(numeros, tamanho);

    printf("Temos %d numeros negativos no array\n\n", negativos);
}



int _inserir_numeros(int numeros[])
{
    int numero, i = 0;
    char resposta;

    do
    {
        printf("Digite um numero:\n");
        scanf("%d", &numero);

        numeros[i] = numero;

        i++;

        printf("Deseja colocar mais um numero? (S/N)\n"); //Aqui eh perguntado se o usuario deseja continuar gerando a sequencia
        __fpurge(stdin);
        scanf("%c", &resposta);

        while( (toupper(resposta) != 'N') && (toupper(resposta) != 'S') ) //Aqui eh garantido que a reposta será sempre 's' ou 'n'
        {
            printf("Nao entendi... Por favor digite 's' ou 'n':\n");
            __fpurge(stdin);
            scanf("%c", &resposta);

        }

    }while(toupper(resposta) != 'N');

    return i;
}



int _quantidade_numeros_negativos(int numeros[], int tamanho)
{
    int quantidade_numeros_negativos = 0;

    for(int i = 0; i < tamanho; i++)
    {

        if(numeros[i] < 0) 
        {
            quantidade_numeros_negativos++; // Aqui eh usado um metodo iterativo simples para verificar quantos
                                            // numeros sao menores que 0
        }

    }

    return quantidade_numeros_negativos;

}
