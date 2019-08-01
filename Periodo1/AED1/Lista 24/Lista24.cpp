#include <iostream>
#include <bits/stdc++.h>

// Efeito 
    void transicao()
{
    std::cout << "------------------------------------------------------------" << std::endl;
}

//Os tratamentos de excessao estao nas classes SemMemoria e ForaDeIntervalo. Suas implementacoes
//estao nas linhas 349 e 386

class SemMemoria:public std::runtime_error
{
    public:
        SemMemoria(): std::runtime_error("Sem memoria---Ja foram criados 100 triangulos\n"){}
};

class ForaDeIntervalo:public std::runtime_error
{
    public:
        int n;
        ForaDeIntervalo(int n):std::runtime_error("Tentando accesar um intervalo nao definido no arranjo na linha ")
        {
            this->n = n;
        }
};

class Triangulo
{
    private:
    double Lado1, Lado2, Lado3;
    static int quantTriangulos; 

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
    // Aqui é comeca um overload com funcoes set que aceitam um parametro, visto que elas sao
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
    // Terminado o overload
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

//Construtores --- Resposta da questao 1 Lista 22
    Triangulo(float lado1, float lado2, float lado3)
    {
        this->Lado1 = lado1;
        this->Lado2 = lado2;
        this->Lado3 = lado3;
    }

    Triangulo(float lado1)
    {
        this->Lado1 = lado1;
        this->Lado2 = lado1;
        this->Lado3 = lado1;
    }

    Triangulo()
    {
        this->Lado1 = 0;
        this->Lado2 = 0;
        this->Lado3 = 0;
    }

    // Aumenta em 1 a variavel. Sempre que um triangulo é criado, essa funcao é chamada
    // Resposta da questao 2 --- Lista 22
    void static aumentarQuantidadeTriangulos()
    {
        quantTriangulos++;
    }

    //Usada para verificar se o triangulo existe, como pede a questao 3 da lista 22
    bool trianguloExiste()
    {
        bool existe = false;

        if( (getLado2() - getLado3() < getLado1()) && (getLado1() < getLado2() + getLado3()) && 
            (getLado1() - getLado3() < getLado2()) && (getLado2() < getLado1() + getLado3()) && 
            (getLado1() - getLado2() < getLado3()) && (getLado3() < getLado1() + getLado2()))
        {
            existe = true;
        }   
    }

    //Resposta da questao 4.2 --- Lista 22
    void static listarCaracteristicasTriangulos(Triangulo arrayPonteiroTriangulos[])
    {
        double lado1, lado2, lado3, perimetro;
        transicao();
        for(int i = 0; i < quantTriangulos; i++)
        {
            std::cout << "Informacoes do triangulo numero " << i + 1 << ":" << std::endl;
            lado1 = arrayPonteiroTriangulos[i].getLado1();
            lado2 = arrayPonteiroTriangulos[i].getLado2();
            lado3 = arrayPonteiroTriangulos[i].getLado3();
            perimetro = arrayPonteiroTriangulos[i].perimetro();
            
            transicao();
            printf("Lado:\t1 = %lf\n\t2 = %lf\n\t3 = %lf\n\nPerimetro = %lf\n", lado1, lado2, lado3, perimetro);
            transicao();
        }
    }


    //Resposta da questao 4.3 --- Lista 22
    void static quantTriangulosIguais(Triangulo arrayPonteiroTriangulos[])
    {
        int quantTriangulosIguais = 0, jaListados[Triangulo::quantTriangulos], index = 0, flag;

        for(int i = 0; i < quantTriangulos; i++)
        {
            flag = 0;
            for(int j = 0; j < index; j++)
            {
                if(jaListados[j] == i)
                {
                    flag = 1;
                }
            }
            if(flag == 0)
            {
                for(int j = i + 1; j < quantTriangulos; j++)
                {
                    if(arrayPonteiroTriangulos[i].triangulosIguais(arrayPonteiroTriangulos, j))
                    {
                        quantTriangulosIguais++;
                        jaListados[index] = j;
                        index++;
                    }
                }
            }
        }
        if(quantTriangulosIguais > 0)
        {
            quantTriangulosIguais++;
        }
        std::cout << "Temos " << quantTriangulosIguais << " triangulos iguais" << std::endl;
    }

    //Resposta da questao 4.4 --- Lista 22
    void static listarTriangulosPorTipo(Triangulo arrayPonteiroTriangulos[])
    {
        int tipo, quantidade = 0;
        do
        {    
        std::cout << "Digite\n\t1 para contar equilateros\n\t2 para contar isosceles\n\t3 para contar escalenos" << std::endl;
        std::cin >> tipo;
        }while( (tipo != 1) && (tipo != 2) && (tipo != 3));

        for(int i = 0; i < quantTriangulos; i++)
        {
            if( (tipo == 1) && (arrayPonteiroTriangulos[i].tipoTriangulo() == "Equilatero\n"))
            {
                quantidade++;
            }
            else if( (tipo == 2) && (arrayPonteiroTriangulos[i].tipoTriangulo() == "Isosceles\n"))
            {
                quantidade++;
            }
            else if( (tipo == 3) && (arrayPonteiroTriangulos[i].tipoTriangulo() == "Escaleno\n"))
            {
                quantidade++;    
            }
        }
        transicao();
        std::cout << "Temos " << quantidade << " triangulos ";

        if(tipo == 1)
            std::cout << "Equilateros" << std::endl;
        else if(tipo == 2)
            std::cout << "Isosceles" << std::endl;
        else if(tipo == 3)
            std::cout << "Escaleno" << std::endl;
    }

    //Resposta da questao 4.5 --- Lista 22. É um overload da resposta da questao 3 da mesma lista
    void static trianguloExiste(Triangulo arrayPonteiroTriangulos[])
    {
        for(int i = 0; i < quantTriangulos; i++)
        {
            if(arrayPonteiroTriangulos[i].tipoTriangulo() == "Nao existe\n")
            {
                transicao();
                std::cout << "O triangulo numero " << i + 1 << " nao pode existir!" << std::endl;
                transicao();
            }
        }
    }
};

int Triangulo::quantTriangulos = 0;

void agradecimento();

void menu();

//A parte da lista 21 foi comentada 


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
    try
    {
        std::cout << "Selecione dois triangulos [1-5] diferentes para comparar..." << std::endl;
        std::cin >> index1;
        std::cin >> index2;
        if((index1 < 1 || index1 > 5) || (index2 < 1 || index2 > 5) || (index1 == index2))
        {
            throw (ForaDeIntervalo(__LINE__ - 2));
        }
    }

    catch(ForaDeIntervalo linha)
    {
        std::cout << linha.what() << linha.n <<"!";
        exit(1);
    }
    transicao();

    // Verificando se os dois triangulos sao iguais
    if(arrayTriangulos[index2 - 1].triangulosIguais(arrayTriangulos, index1 - 1) == true) 
        std::cout << "Os triangulos sao iguais" << std::endl;
    else 
        std::cout << "Os triangulos sao diferentes" << std::endl;

    


    // Array de ponteiro para triangulos
    Triangulo *arrayPonteiroTriangulos = new Triangulo[100];
    int resp, i = 0;
    do
    {
        menu();
        std::cin >> resp;

        if(resp == 1)
        {
            try
            {
            if(i == 100)
            {
                throw(SemMemoria());
            }

            arrayPonteiroTriangulos[i].digitarLados();
            i++;
            Triangulo::aumentarQuantidadeTriangulos();
            
            }
            catch(SemMemoria erro)
            {
                std::cout << erro.what();
                exit(1);
            }
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
