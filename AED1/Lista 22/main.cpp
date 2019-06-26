#include "triangulo.h"

int Triangulo::quantTriangulos = 0;

void agradecimento();

void menu();

//A parte da lista 21 foi comentada 


int main() 
{
    /*
    Triangulo t1;
    t1.setLado1(1);
    t1.setLado2(1);
    t1.setLado3(1);
    std::cout << "Perimetro do tiangulo = " << t1.perimetro() << std::endl;
    std::cout << "Tipo do tiangulo = " << t1.tipoTriangulo() << std::endl;

    transicao();

    Triangulo t2;
    t2.digitarLados();
    std::cout << "\nPerimetro do triangulo = " << t2.perimetro() << std::endl;
    std::cout << "Tipo do triangulo = " << t2.tipoTriangulo() << std::endl;

    transicao();

    Triangulo arrayTriangulos[5];
    for(int i = 0; i < 5; i++)
    {
        std::cout << "Inserindo informacoes para o " << i + 1 << " triangulo....\n" << std::endl;
        arrayTriangulos[i].digitarLados();
        std::cout << "\nTipo do " << i + 1 <<" triangulo = " << arrayTriangulos[i].tipoTriangulo() << std::endl;
        std::cout << "\nPerimetro do " << i + 1 << " triangulo = " << arrayTriangulos[i].perimetro() << std::endl;
        transicao();
    }

    // Aqui sao selecionados quais triangulos do array vao ser comparados
    int index1, index2;
    do
    {
        std::cout << "Selecione dois triangulos [1-5] diferentes para comparar..." << std::endl;
        std::cin >> index1;
        std::cin >> index2;
    } while( (index1 < 1 || index1 > 5) || (index2 < 1 || index2 > 5) || (index1 == index2));

    transicao();

    // Verificando se os dois triangulos sao iguais
    if(arrayTriangulos[index2 - 1].triangulosIguais(arrayTriangulos, index1 - 1) == true) 
        std::cout << "Os triangulos sao iguais" << std::endl;
    else 
        std::cout << "Os triangulos sao diferentes" << std::endl;

    */
    


    // Array de ponteiro para triangulos
    Triangulo *arrayPonteiroTriangulos = new Triangulo[100];
    int resp, i = 0;
    do
    {
        menu();
        std::cin >> resp;

        if(resp == 1)
        {
            arrayPonteiroTriangulos[i].digitarLados();
            i++;
            Triangulo::aumentarQuantidadeTriangulos();
        }
        else if(resp == 2)
        {
            Triangulo::listarCaracteristicasTriangulos(arrayPonteiroTriangulos);
        }
        else if(resp == 3)
        {
            Triangulo::quantTriangulosIguais(arrayPonteiroTriangulos);
        }
        else if(resp == 4)
        {
            Triangulo::listarTriangulosPorTipo(arrayPonteiroTriangulos);
        }
        else if(resp == 5)
        {
            Triangulo::trianguloExiste(arrayPonteiroTriangulos);
        }
    } while (resp != 0);

    delete arrayPonteiroTriangulos;
    
    transicao();
    agradecimento();
    transicao();
    return 0;
} 

void agradecimento()
{
    std::cout << "Obrigado por usar :)" << std::endl;
}

void menu()
{
    std::cout << "Digite:\n\t0 para sair\n\t1 para criar um triangulo\n\t2 para listar os triangulos\n\t3 para verificar o numero de triangulos iguais\n\t4 para listar triangulos de acordo com tipo\n\t5 para verificar inconsistencias" << std::endl;
}
