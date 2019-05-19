#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int _contar_negativos(int numeros[], int posicao, int quantidade_numeros_negativos);

int _inserir_numeros(int numeros[]);

int main()
{

    int numeros[100], negativos, tamanho;

    tamanho = _inserir_numeros(numeros); // Essa funcao insere numeros no array e retorna um valor i. Esse valor i 
                                         // eh gerado depois de iteracoes em um loop for, logo ele acaba 
                                         // sendo um modo informal de saber quantos numeros existem no array




    negativos = _contar_negativos(numeros, tamanho, 0);             /*
                                                                    
                                                                     Esse '0' sera interpretado pela funcao como
                                                                     uma variavel inteira que eh responsavel por contar
                                                                     a quantidade de negativos no array, logo eh passado o valor
                                                                     '0' para que ela se incremente por recursao. A variavel
                                                                     'tamanho' será, para a funcao, um tipo de contador
                                                                     de posicoes do array. Veja comentarios na funcao!
                                                                    
                                                                    */

    printf("\nTemos %d numeros negativos no array\n\n", negativos); 

    return 0;
}


int _inserir_numeros(int numeros[])
{
    int numero, i = 0;
    char resposta;

    do
    {
        printf("Digite um numero:\n");
        scanf("%d", &numero); //Numero sera pego pelo teclado e inserido no array

        numeros[i] = numero;

        i++;

        printf("Deseja colocar mais um numero? (S/N)\n"); //Aqui eh perguntado se o usuario deseja continuar digitando numeros
        __fpurge(stdin);
        scanf("%c", &resposta);

        while( (toupper(resposta) != 'N') && (toupper(resposta) != 'S') ) //Aqui checa se a resposta do usuario eh 's' ou 'n'
        {
            printf("Nao entendi... Por favor digite 's' ou 'n':\n");
            __fpurge(stdin);
            scanf("%c", &resposta);

        }

    }while(toupper(resposta) != 'N'); // Eh repetido esse processo de se obter numeros ate que o usuario digite 'n' ou 'N'

    return (i - 1);
}




int _contar_negativos(int numeros[], int posicao, int quantidade_numeros_negativos)
{

    if(posicao >= 0)
    {
        numeros[posicao] < 0
        ? quantidade_numeros_negativos += 1
        : 0; // Se o numero na posicao 'posicao' do array 'numeros' for menor que '0', a variavel 'quantidade_numeros_negativos'
             // aumenta em 1   


        quantidade_numeros_negativos = _contar_negativos(numeros, (posicao - 1), quantidade_numeros_negativos);

         /* 
         
         A funcao eh chamada de novo, mas ela so sera chamada enquanto a variavel 'posicao' for maior que '0'. Alem disso, 
         sempre que chamada, a funcao passa o valor 'posicao' diminuido em 1. Isso faz com que a funcao cheque o array
         da ultima posicao ate a primeira --- Se tiver 6 numeros no array numeros[], ela comecará em numeros[5] e ira ate  
         numeros[0] --- (ela foi chamada na main() usando a variavel tamanho, e vai diminuindo).
         Da mesma forma, a variavel 'quantidade_numeros_negativos' tambem eh passada, e seu valor eh mantido. Isso faz
         com que o valor de 'quantidade_numeros_negativos' obtido depois de se checar o numeros[0] seja reenvido ate a primeira
         chamada da funcao '_contar_negativos()', e, finalmente, retornado para a 'main()'

        */

    }

    return quantidade_numeros_negativos;

}
