#include <iostream>
#include <regex>

int main()
{
    std::regex a("Raf.*");
    std::string b = "Rafael";
    if(std::regex_search(b, a))
    {
        std::cout << "As duas sao iguais\n";
    }
    return 0;
}