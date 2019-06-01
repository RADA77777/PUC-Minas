#include <iostream>

inline bool checar_Se_Primo(int numero);

int main()
{
    std::cout << "Quantas numeros deseja checar?" << std::endl;
    
    int vezes;

    std::cin >> vezes;

    long long int numero;
    bool primo;

    for(int i = 0; i < vezes; i++)
    {   
        primo = true;
        std::cout << "Digite um numero: ";
        std::cin >> numero;
        primo = checar_Se_Primo(numero);

        if(primo == true)
        {
            std::cout << "O numero " << numero << " é primo" << std::endl; 
        }

        else
        {
            std::cout << "O numero " << numero << " não é primo" << std::endl; 
        }
        
    }
    return 0;
}

inline bool checar_Se_Primo(int numero)
{   
    bool primo = true;
    
    for(int i = 2; i < numero; i++)
    {
        if(numero %2 == 0)
        {
            primo = false;
            break;
        }
    }

    return primo;
}