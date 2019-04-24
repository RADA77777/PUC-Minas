#include <stdio.h>
#include <stdlib.h>

int main() {

    int nota1, nota2;
    printf("Digite as notas obtidas nas provas 1 e 2\n");
    scanf("%d%d", &nota1, &nota2);

    if( (nota1 + nota2) > 60){
        printf("O aluno passou\n");
    }
    else if( (nota1 + nota2) <= 60 && (nota1 + nota2) > 40){
        printf("O aluno esta em reavaliacao\n");
    }
    else{
        printf("O aluno esta reprovado\n");
    }

    return 0;
}