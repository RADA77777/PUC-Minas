#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _trocar(float array[], int posicao1, int posicao2);

void _preencher(float array[]);

void _escrever(float array[], int posicao1, int posicao2);

void _le_real(int *posicao);

int main()
{


    float array[100];
    int posicao1, posicao2;


    _le_real(&posicao1);
    _le_real(&posicao2); // Le duas posicoes para trocar os numeros

    _preencher(array);

    _trocar(array, posicao1, posicao2);


    _escrever(array, posicao1, posicao2);

    return 0;
}

void _trocar(float array[], int posicao1, int posicao2)
{
    float aux = array[posicao1];
    array[posicao1] = array[posicao2];
    array[posicao2] = aux; // Troca os numeros da posicoes especificadas

}
void _preencher(float array[])
{
     for(int i = 0; i < 100; i++)
    {
        array[i] = i; // Preenche o array com numeros de 0 a 100

    }
}

void _escrever(float array[], int posicao1, int posicao2)
{
    printf("O da posicao %d agora eh %f\n",posicao1, array[posicao1]);
    printf("O da posicao %d agora eh %f\n",posicao2, array[posicao2]); // Printa os numeros da posicao '0' e da posicao '99'
}

void _le_real(int *posicao)
{
    printf("Digite a posicao:\n");
    scanf("%d", posicao); //Le o valor de uma posicao e o armazena no endereco

}