#include "PmergeMe.hpp"

//while pushing to vector, start assigning those pairs to struct? enum?

int main(int argc, char **argv)
{
    PmergeMe obj;
    std::stringstream ss;

    if (argc == 2)
        return std::cout << "Nothing to sort." << std::endl, 0;
    for (int i = 1; i < argc; i++)
        ss << argv[i] << " ";
    try 
    {
        obj.validateInput(ss);
    }
    catch (std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}