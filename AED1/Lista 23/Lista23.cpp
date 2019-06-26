#include <iostream>
#include <math.h>

//Superclasse
class FigGeometrica
{
    protected:
        static int Quantidade;
	public:
        FigGeometrica()
        {
            Quantidade++;
        }
		double virtual perimetro()=0;
		double virtual area()=0;
		int static quantidade()
        {
            return Quantidade;
        }
};

//Subclasses
class Circulo: public FigGeometrica
{
    private:
	    double raio;
        static int Quantidade;
    public:
        Circulo()
        {
            Circulo::Quantidade++;
        }
        Circulo(double raio) : raio(raio)
        {
            Circulo::Quantidade++;
        }
        void setRaio(double raio)
        {
            this->raio = raio;
        }
        double getRaio()
        {
            return this->raio;
        }
        double perimetro()
        {
            return (2 * M_PI * this->raio);
        }
        double area()
        {
            return (pow(raio,2) * M_PI);
        }
        int static quantidade()
        {
            return Circulo::Quantidade;
        }
};

class Quadrado: public FigGeometrica
{
    private:
	    double lado;
        static int Quantidade;
    public:
        Quadrado()
        {
            Quadrado::Quantidade++;
        }
        Quadrado(double lado)
        {
            setLado(lado);
            Quadrado::Quantidade++;
        }
        double perimetro()
        {
            return (this->lado * 4);
        }
        double area()
        {
            return (this->lado * this->lado);
        }
        int static quantidade()
        {
            return Quadrado::Quantidade;
        }
        double getLado()
        {
            return this->lado;
        }
        void setLado(double lado)
        {
            this->lado = lado;
        }
};

class Triangulo: public FigGeometrica
{
    private:
	    double a, b, c;
        static int Quantidade;
    public:
        void setTriangulo(double a, double b, double c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        Triangulo()
        {
            Triangulo::Quantidade++;
        }
        Triangulo(double a)
        {
            setTriangulo(a, a, a);
            Triangulo::Quantidade++;
        }
        Triangulo(double a, double b, double c)
        {
            setTriangulo(a, b, c);
            Triangulo::Quantidade++;
        }
        double getA()
        {
            return this->a;
        }
        double getB()
        {
            return this->b;
        }
        double getC()
        {
            return this->c;
        }
        double perimetro()
        {
            return (this->a + this->b + this->c);
        }
        double area()
        {
                double semiperimetro = this->perimetro() / 2;
                return (sqrt(semiperimetro * (semiperimetro - this->getA()) * (semiperimetro - this->getB()) * (semiperimetro - this->getC())));
        }
        bool valido()
        {
            bool valido = false;
            if( (getB() - getC() < getA()) && (getA() < getB() + getC()) && 
                (getA() - getC() < getB()) && (getB() < getA() + getC()) && 
                (getA() - getB() < getC()) && (getC() < getA() + getB()))
            {
                valido = true;
            }
            return valido;
        }
        int static quantidade()
        {
            return Triangulo::Quantidade;
        }
};
int FigGeometrica::Quantidade = 0;
int Triangulo::Quantidade = 0;
int Quadrado::Quantidade = 0;
int Circulo::Quantidade = 0;

int menu();
void agradecimento();
void criarCirculo(Circulo *arrayCirculos[]);
void criarQuadrado(Quadrado *arrayQuadrados[]);
void criarTriangulo(Triangulo *arrayTriangulos[]);

int main()
{
    Circulo *arrayCirculos[100];
    Quadrado *arrayQuadrados[100];
    Triangulo *arrayTriangulos[100];
    int resposta;
    do
    {
        std::cout << "No momento ha " << FigGeometrica::quantidade() << " figuras geometricas, sendo:\n" << Circulo::quantidade() << " Circulos\n" << Quadrado::quantidade() << " Quadrados\n" << Triangulo::quantidade() << " Triangulos\n";
        resposta = menu(); 
        if(resposta == 1)
        {
            criarCirculo(arrayCirculos);
        }
        else if(resposta == 2)
        {
            criarQuadrado(arrayQuadrados);
        }
        else if(resposta == 3)
        {
            criarTriangulo(arrayTriangulos);
        }
    } while(resposta != 0);
    agradecimento();
}

int menu()
{
    int resposta;
    std::cout << "Digite:\n[0] para sair\n[1] para acessar circulos\n[2] para acessar quadrados\n[3] para acessar triangulos\n";
    std::cin >> resposta;
    return resposta;
}

void agradecimento()
{
    std::cout << "Obrigado por usar o programa!" << std::endl;
}

void criarCirculo(Circulo *arrayCirculos[])
{
    double raio;
    int resposta2, quantidadeCirculos = Circulo::quantidade(), index;
    do
    {
        std::cout << "Digite\n[0] para voltar\n[1] para criar um circulo\n[2] para listar informacoes dos circulos existentes\n";
        std::cin >> resposta2;
        if(resposta2 == 1)
        {
            std::cout << "Digite o raio do circulo:\n";
            std::cin >> raio;
            arrayCirculos[quantidadeCirculos] = new Circulo(raio);
            quantidadeCirculos = Circulo::quantidade();
        }
        if(resposta2 == 2)
        {
            index = 0;
            while (index < Circulo::quantidade())
            {
                printf("O circulo numero %d, de raio %lf, tem perimetro igual a %lf e area igual a %lf\n\n", (index + 1), arrayCirculos[index]->getRaio(), arrayCirculos[index]->perimetro(), arrayCirculos[index]->area());
                index++;
            }
        }
    } while(resposta2 != 0);
}

void criarQuadrado(Quadrado *arrayQuadrados[])
{
    double lado;
    int resposta2, quantidadeQuadrados = Quadrado::quantidade(), index;
    do
    {
        std::cout << "Digite\n[0] para voltar\n[1] para criar um quadrado\n[2] para listar informacoes dos quadrados existentes\n";
        std::cin >> resposta2;
        if(resposta2 == 1)
        {
            std::cout << "Digite o lado do quadrado:\n";
            std::cin >> lado;
            arrayQuadrados[quantidadeQuadrados] = new Quadrado(lado);
            quantidadeQuadrados = Quadrado::quantidade();
        }
        if(resposta2 == 2)
        {
            index = 0;
            while (index < Quadrado::quantidade())
            {
                printf("O quadrado numero %d, de lado %lf, tem perimetro igual a %lf e area igual a %lf\n\n", (index + 1), arrayQuadrados[index]->getLado(), arrayQuadrados[index]->perimetro(), arrayQuadrados[index]->area());
                index++;
            }
        }
    } while(resposta2 != 0);
}

void criarTriangulo(Triangulo *arrayTriangulos[])
{
    double a, b, c;
    int resposta2, resposta3, quantidadeTriangulos = Triangulo::quantidade(), index;
    do
    {
        std::cout << "Digite\n[0] para voltar\n[1] para criar um triangulo\n[2] para listar informacoes dos triangulos existentes\n";
        std::cin >> resposta2;
        if(resposta2 == 1)
        {
            do
            {
                std::cout << "Digite\n[0] para voltar\n[1] para criar um triangulo equilatero\n[2] para escolher os lados\n";
                std::cin >> resposta3;
                if(resposta3 == 1)
                {
                    std::cout << "Digite o lado do triangulo:\n";
                    std::cin >> a;
                    arrayTriangulos[quantidadeTriangulos] = new Triangulo(a);
                    quantidadeTriangulos = Triangulo::quantidade();
                }
                else if(resposta3 == 2)
                {
                    std::cout << "Digite os lados A, B e C\n";
                    std::cin >> a, std::cin >> b, std::cin >> c;
                    arrayTriangulos[quantidadeTriangulos] = new Triangulo(a, b, c);
                    quantidadeTriangulos = Triangulo::quantidade();
                }
            } while(resposta3 != 0);
        }
        if(resposta2 == 2)
        {
            index = 0;
            while (index < Triangulo::quantidade())
            {
                if(arrayTriangulos[index]->valido())
                {
                    printf("O triangulo numero %d, de lados %lf, %lf e %lf, tem perimetro igual a %lf e area igual a %lf\n\n", (index + 1), arrayTriangulos[index]->getA(), arrayTriangulos[index]->getB(), arrayTriangulos[index]->getC(), arrayTriangulos[index]->perimetro(), arrayTriangulos[index]->area());
                    index++;
                }
                else
                {
                    std::cout << "O triangulo numero " << index + 1 << " nao eh valido\n\n";
                    index++;
                }
                
            }
        }
    } while(resposta2 != 0);
}