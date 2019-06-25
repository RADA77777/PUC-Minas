#include <iostream>
#include <math.h>

//Superclasse
class FigGeometrica
{
    private:
        static int Quantidade;
	public:
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
        Circulo(double raio)
        {
            setRaio(raio);
            quantidade();
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
            quantidade();
            Quadrado::Quantidade++;
        }
        double perimetro()
        {
            return (this->lado * this->lado);
        }
        double area()
        {
            return (this->lado * 4);
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
                double altura = sqrt(pow(getB(), 2) - pow(getA()/2 , 2));
                return ((getA() * altura) / 2);
        }

        bool valido()
        {
            bool valido = false;
            if( (getB() - getC() < getA()) && (getA() < getB() + getC()) || 
                (getA() - getC() < getB()) && (getB() < getA() + getC()) || 
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
int main()
{
    Circulo *arrayDeCirculos[100];
    Quadrado *arrayDeQuadrados[100];
    Triangulo *arrayDeTriangulos[100];
    int resposta, i = 0;
    double raio, lado, a, b, c;
    do
    {
        resposta = menu(); 
        if(resposta == 1)
        {
            std::cin >> raio;
            arrayDeCirculos[i] = new Circulo;
            arrayDeCirculos[i]->setRaio(raio);
            std :: cout << "O Raio eh " << arrayDeCirculos[i]->getRaio() << std::endl;
        }
    } while(resposta != 0);
    std::cout << "Temos " << Circulo::quantidade() << " circulos\n";
    agradecimento();
}

int menu()
{
    int resposta;
    std::cout << "Digite:\n\t0 para sair\n\t1 para criar circulos\n\t2 para criar quadrados\n\t3 para criar triangulos" << std::endl;
    std::cin >> resposta;
    return resposta;
}

void agradecimento()
{
    std::cout << "Obrigado por usar o programa!" << std::endl;
}