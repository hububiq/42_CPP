#include "Span.hpp"

int main()
{
    Span b(5);

    std::cout << b.getVector().size() << std::endl;
    for (size_t i = 0; i < b.getVector().size(); i++)
        std::cout << b.getVector()[i] << " ";
    std::cout << std::endl; 
    b.addNumber(5);
    for (size_t i = 0; i < b.getVector().size(); i++)
        std::cout << b.getVector()[i] << " ";
    b.addNumber(7);
    for (size_t i = 0; i < b.getVector().size(); i++)
        std::cout << b.getVector()[i] << " ";
    return 0;
}
