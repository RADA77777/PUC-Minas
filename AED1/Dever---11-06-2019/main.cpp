#include <iostream>
#include <bits/stdc++.h> 

void transicao()
{
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
}

class Triangulo
{
    private:
    double Lado1, Lado2, Lado3;

    public:

    // inicio declaracao de gets e sets para cada lado do triangulo
    void setLado1()
    {
        std::cin >> this->Lado1;
    }
    void setLado2()
    {
        std::cin >> this->Lado2;
    }
    void setLado3()
    {
        std::cin >> this->Lado3;
    }
    // Aqui é comeca um override com funcoes set que aceitam um parametro, visto que elas sao
    // necessarias para fazer a questao 1
    void setLado1(double lado)
    {
        this->Lado1 = lado;
    }
    void setLado2(double lado)
    {
        this->Lado2 = lado;
    }
    void setLado3(double lado)
    {
        this->Lado3 = lado;
    }
    // Terminado o override
    double getLado1()
    {
        if(this->Lado1 < 0)
        {
           return 0;
        }
        return this->Lado1;
    }
    double getLado2()
    {
        if(this->Lado2 < 0)
        {
           return 0;
        }
        return this->Lado2;
    }
    double getLado3()
    {
        if(this->Lado3 < 0)
        {
           return 0;
        }
        return this->Lado3;
    }
    // final gets e sets

    // essa funcao retorna o perimetro do triangulo
    double perimetro()
    {
        return (getLado1() + getLado2() + getLado3());
    }

    // funcao para checar o tipo (isoceles-escaleno-equilatero) do triangulo
    std::string tipoTriangulo()
    {       
        // Formula para validar existencia de um triangulo
        if( (getLado2() - getLado3() < getLado1()) && (getLado1() < getLado2() + getLado3()) || 
            (getLado1() - getLado3() < getLado2()) && (getLado2() < getLado1() + getLado3()) || 
            (getLado1() - getLado2() < getLado3()) && (getLado3() < getLado1() + getLado2()))
        {   
            if( (this->getLado1() == this->getLado2()) && (this->getLado2() == this->getLado3()))
            {
                return "Equilatero\n"; 
            }

            else if( (this->getLado1() != this->getLado2()) && 
                     (this->getLado1() != this->getLado3()) && 
                     (this->getLado2() != this->getLado3()) )
            {
                return "Escaleno\n";
            }
            else
            {
                return "Isosceles\n";
            }
        }
        else
        {
            return "Nao existe\n";
        }
    }
    
    // essa funcao insere de uma vez os lados, para nao ter que chamar individualmente o 
    // metodo set de cada lado do triangulo
    void digitarLados()
    {
        std::cout << "Digite o lado 1 do triangulo:" << std::endl;
        this->setLado1();
        std::cout << "Digite o lado 2 do triangulo:" << std::endl;
        this->setLado2();
        std::cout << "Digite o lado 3 do triangulo:" << std::endl;
        this->setLado3();
    }

    // funcao para checar se um triangulo do array que foi passado por referencia eh igual
    // ao triangulo objeto que chamou o metodo
    bool triangulosIguais(Triangulo arrayTriangulos[], int index)
    {
        bool saoIguais = false;
        double ladosTriangulo1[3] = {this->getLado1(), this->getLado2(), this->getLado3()};
        double ladosTriangulo2[3] = {arrayTriangulos[index].getLado1(), arrayTriangulos[index].getLado2(), arrayTriangulos[index].getLado3()};
        
        std::sort(ladosTriangulo1, ladosTriangulo1 + 3);
        std::sort(ladosTriangulo2, ladosTriangulo2 + 3);
        // Os lados dos dois triangulos sao colocados em ordem crescente

        if(ladosTriangulo1[0] == ladosTriangulo2[0] &&
           ladosTriangulo1[1] == ladosTriangulo2[1] &&
           ladosTriangulo1[2] == ladosTriangulo2[2])
           {
               saoIguais = true;
           }

        return saoIguais;
    }
};

int main()
{
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

    return 0;
}