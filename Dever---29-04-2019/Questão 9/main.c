#include<stdlib.h>
#include<stdio.h>

int _fibonacci(int n,int termo1,int termo2);
int _lertermo();


int main()
{
        int fibonacci,
            termo;
        termo=_lertermo();
        fibonacci=_fibonacci(termo,1,0);
        printf("\n%d\t",fibonacci);
        return 0;
}


int _fibonacci(int n,int termo1,int termo2){
        int aux=0;//variavel auxiliar

        if(n >= 1){

                aux=termo1+termo2;
                termo2=termo1;
                termo1=aux;

                printf("%d\n", termo1);
                _fibonacci( (n - 1), termo1, termo2 );
                
        }

        return aux;
}

int _lertermo()
{
        int termo;
        printf("\nDigite qual o termo que deseja ser mostrado: ");
        scanf("%d",&termo);
        return termo;
}