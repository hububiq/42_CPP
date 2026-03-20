#include "PmergeMe.hpp"

//enum to differ containers?
//int overflow?
//looping with for is quick on i.e. 3000 numbers. new/malloc or creating subvectors will take processor time for memory management

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
        obj.executeAlgo();
    }
    catch (std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}