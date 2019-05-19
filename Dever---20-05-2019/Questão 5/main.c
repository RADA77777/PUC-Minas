#include <stdio.h>
#include <stdlib.h>

int _soma_idades(int *idades, int quantidade_alunos);

int _check(int n, int liminf, int limsup);

float _idade_media(int *idades, int quantidade_alunos);

int _quantidade_acima_media(int *idades, int quantidade_alunos);

int _leIdade();



int main()
{

    int idade, flag = 0, quantidade_acima_media, i = 0; 

    int *idades = (int*)malloc( sizeof(int));


    idade = _leIdade();

    while(idade != flag)
    {
        idades = realloc(idades, sizeof(int) * (i+1)); // A variavel i serve pra marcar em qual posicao do array idades estamos, logo 
                                                       // (i+1) serve pra nos dizer quantos alunos temos
        
        idades[i] = idade;

        i++;
        idade = _leIdade();
    }

    quantidade_acima_media = _quantidade_acima_media(idades, i ); // Basta passar o array idades e o numero de alunos para calcular


    printf("A idade media da sala eh %.3f e a quantidade de alunos com idade acima dela eh %d\n\n", _idade_media(idades, i ), quantidade_acima_media);

    free(idades);

    return 0;

}



int _leIdade()
{
    int idade;
    printf("Digite uma idade ou '0' para sair:\n");
    scanf("%d", &idade);

    idade = _check(idade, 0 , 150); // Eh lido um numero e mandado para a funcao _check validar. Se ele voltar ok, eh retornado idade
                                    // para a variavel que chamou a funcao

    return idade;

}



int _check(int n, int liminf, int limsup)
{

    if(n < liminf || n > limsup){
        printf("Valor fora do escopo %d-%d\n", liminf, limsup);
        n = _leIdade(); /* 
        
                        Enquanto a variavel estiver fora do limite superior ou do limite inferior, eh chamada novamente
                        a funcao _leIdade() para obter outra idade, e eh mantido esse ciclo ate que seja digitada uma
                        idade que esta dentro do escopo. Essa variavel aceitada sera retornada para _leIdade(), que por vez
                        retorna a idade válida para _check(). _check() armazena em N, e retorna N para _leIdade() de novo,
                        ate "desempilhar" tudo, fazendo com que o unico valor retornado por _leIdade() sejam valores aceitos
                        
                        */

                        }

    return n;

}


int _soma_idades(int *idades, int quantidade_alunos)
{
    int soma_idades = 0;

    for(int i = 0; i < quantidade_alunos; i++){

        soma_idades += idades[i];

    }


    return soma_idades;
}

float _idade_media(int *idades, int quantidade_alunos)
{
    int soma_idades = _soma_idades(idades, quantidade_alunos); 

    float idade_media;


    idade_media = (float)soma_idades / quantidade_alunos; // Funcao calcula uma media simples, usando valores do array idades[]


    return idade_media;
}



int _quantidade_acima_media(int *idades, int quantidade_alunos)
{
    float idade_media = _idade_media(idades, quantidade_alunos); // Aqui eh chamada a funcao que calcula a idade media, que
                                                                 // retorna seu valor para a variavel idade_media


    int quantidade_acima_media = 0;

    for(int i = 0; i < quantidade_alunos; i++)
    {

        if(idades[i] > idade_media)
        {

            quantidade_acima_media++; // Aqui eh checado se a idade na posicao i eh maior q a media calculada. Se for, 
                                      // eh aumentado em 1 a quantidade de idades acima da media, para depois retornar

        }

    } 


    return quantidade_acima_media;
}

