#include "Span.hpp"

int main()
{
    Span b(10);


    try
    {
        b.addNumber(8);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(138);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(110);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(1000);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(1200);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(99);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(152);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(1012);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(200);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        b.addNumber(2020);
        for (size_t i = 0; i < b.getVector().size(); i++)
            std::cout << b.getVector()[i] << " ";
        std::cout << std::endl;
    }
    catch (std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << b.longestSpan() << std::endl;
        std::cout << b.shortestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Not enough arguments to measure distance" << std::endl;
    }
    return 0;
}
