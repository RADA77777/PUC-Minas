#include <stdio.h>
#include <stdlib.h>

void leReal(int *real);
void escrever(int real);
int _meio(int x, int y, int z);


int main()
{

    int x, y, z, maior;
    
    printf("Digite 3 números para saber o do meio:\n");
    leReal(&x);
    leReal(&y);
    leReal(&z);

    maior = _meio(x, y, z);

    escrever(maior);
    return 0;
}

void leReal(int *real)
{

    scanf("%d", real);

}

void escrever(int real)
{

    printf("O número do meio vale %d\n\n", real);

}


int _meio(int x, int y, int z)
{

    int numeros[3] = {x, y, z}, flag = 0, meio;
    
    for(int i = 0; i < 3; i++)
    {
        
        for (int j = 0; j < 3; j++)
        {
            
            if( numeros[i] == numeros[j])
            {
                continue;
            }

            else if( numeros[i] > numeros [j])
            {
                flag++;
            }

        }

        if(flag == 1)
        {
            meio = numeros[i];
        }

        flag = 0;        
    }

    return meio;
}