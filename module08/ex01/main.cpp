#include "Span.hpp"
#include <ctime>

/* std::iota - fulfilling vector with numbers from given range
  std::shuffle - mixing them */

int main()
{
    // -------- random generator method for filling vector and insert at once --------

    Span b(30);

    srand(time(NULL));
    size_t i = 0;
    std::vector<int> toInsert;
    b.addNumber(5);
    b.addNumber(6);
    for (int i = 0; i < 2; i++)
        std::cout << b.getVector()[i] << " ";
    while (i < 28)
    {
        int randomInt = rand();
        toInsert.push_back(randomInt);
        i++;
    }
    std::cout << std::endl;
    try
    {
        b.addMultiple(toInsert);
        for (int i = 0; i < 30; i++)
            std::cout << b.getVector()[i] << " ";
        std::cout << b.longestSpan() << " " << b.shortestSpan() << std::endl;
    }
    catch (std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    // --------- Manually filling vector ---------

    // Span b(10);
    // try
    // {
    //     b.addNumber(8);
    //     for (size_t i = 0; i < b.getVector().size(); i++)
    //         std::cout << b.getVector()[i] << " ";
    //     b.addNumber(138);
    //     for (size_t i = 0; i < b.getVector().size(); i++)
    //         std::cout << b.getVector()[i] << " ";
    //     b.addNumber(110);
    //     for (size_t i = 0; i < b.getVector().size(); i++)
    //         std::cout << b.getVector()[i] << " ";
    //     b.addNumber(1000);
    //     for (size_t i = 0; i < b.getVector().size(); i++)
    //         std::cout << b.getVector()[i] << " ";
    //     b.addNumber(1200);
    //     for (size_t i = 0; i < b.getVector().size(); i++)
    //         std::cout << b.getVector()[i] << " ";
    //     b.addNumber(99);
    //     for (size_t i = 0; i < b.getVector().size(); i++)
    //         std::cout << b.getVector()[i] << " ";
    //     b.addNumber(152);
    //     for (size_t i = 0; i < b.getVector().size(); i++)
    //         std::cout << b.getVector()[i] << " ";
    //     b.addNumber(1012);
    //     for (size_t i = 0; i < b.getVector().size(); i++)
    //         std::cout << b.getVector()[i] << " ";
    //     b.addNumber(200);
    //     for (size_t i = 0; i < b.getVector().size(); i++)
    //         std::cout << b.getVector()[i] << " ";
    //     b.addNumber(2020);
    //     for (size_t i = 0; i < b.getVector().size(); i++)
    //         std::cout << b.getVector()[i] << " ";
    //     std::cout << std::endl;
    // }
    // catch (std::out_of_range& e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // try
    // {
    //     std::cout << b.longestSpan() << std::endl;
    //     std::cout << b.shortestSpan() << std::endl;
    // }
    // catch (std::exception& e)
    // {
    //     std::cout << "Not enough arguments to measure distance" << std::endl;
    // }
    return 0;
}
