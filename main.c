#include <stdio.h>
#include <string.h>

int main()
{
    FILE* arq;
    arq = fopen("a.txt", "r");
    int quantMaiusculas = 0;
    char linha[10];
    do
    {
        fscanf(arq, "%s", &linha);
        for(int i = 0; i < strlen(linha); i++)
        {
            if((int)linha[i] >= 65 && (int)linha[i] <= 90)
            {
                quantMaiusculas++;
            }
        }
    } while(strcmp(linha, "FIM") != 0);

    quantMaiusculas -= 3;
    fclose(arq);
    printf("%d", quantMaiusculas);
}