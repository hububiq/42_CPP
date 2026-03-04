#include "Span.hpp"

int main()
{
    Span b(5);

    try
    {
        b.addNumber(5);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(7);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(8);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(9);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(11);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(12);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
    }
    catch (std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Not enough arguments to measure distance" << std::endl;
    }
    return 0;
}
