#include "Span.hpp"

int main()
{
    Span b(5);

    try
    {
        // std::cout << b.getVector().size() << std::endl;
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(5);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(7);
        b.addNumber(8);
        b.addNumber(9);
        b.addNumber(11);
        b.addNumber(12);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        std::cout << "\nMax index " << b.getVector().size() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Can't add over maximum vector size" << std::endl;
    }
    return 0;
}
