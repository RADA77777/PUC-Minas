#include <stdio.h>
#include <stdlib.h>

void leReal(int *real);
void escrever(int real);
void _maior(int x, int y, int *maior);


int main()
{

    int x, y, maior;
    
    printf("Digite dois números para saber o maior:\n");
    leReal(&x);
    leReal(&y);

    _maior(x, y, &maior);

    escrever(maior);
    return 0;
}

void leReal(int *real)
{

    scanf("%d", real);

}

void escrever(int real)
{

    printf("O maior número vale %d\n\n", real);

}


void _maior(int x, int y, int *maior)
{

    if(x > y)
    {
        *maior = x;
    }

    else
    {
        *maior = y;
    }

}