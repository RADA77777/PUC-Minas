#include <stdio.h>
#include <stdlib.h>

void _trocar(int array[]);

void _preencher(int array[]);

void _escrever(int array[]);
int main()
{
    int array[100];

    _preencher(array);
    _trocar(array);

    _escrever(array);

    return 0;
}

void _trocar(int array[])
{
    int aux = array[0];
    array[0]= array[99];
    array[99] = aux; // Troca o numero da posicao '0' com o da posicao '99'

}
void _preencher(int array[])
{
     for(int i = 0; i < 100; i++)
    {
        array[i] = i; // Preenche o array com numeros de 0 a 100

    }
}

void _escrever(int array[])
{
    printf("O primeiro eh %d\n", array[0]);
    printf("O ultimo eh %d\n", array[99]); //printa os numeros da posicao '0' e '99'
}