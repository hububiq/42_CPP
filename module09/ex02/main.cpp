#include "PmergeMe.hpp"

//looping with for is quick on i.e. 3000 numbers. new/malloc or creating subvectors will take processor time for memory management
//vector is continuous segments, deque is separated segments but still fast, probably faster for bigger inputs

int main(int argc, char **argv)
{
    PmergeMe obj;
    std::stringstream ss;
    clock_t before;
    clock_t after;

    if (argc == 2)
        return std::cout << "Nothing to sort." << std::endl, 0;
    for (int i = 1; i < argc; i++)
        ss << argv[i] << " ";
    try 
    {
        before = clock();
        obj.validateInput(ss);
        obj.executeAlgo();
        after = clock();
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    std::cout << "Before:  ";
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;
    std::vector<int> vecShow = obj.getVector();
    std::cout << "After:   ";
    for (int i = 0; i < argc - 1; i++)
        std::cout << vecShow[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " arguments with std::" << "vector is : " <<           //solve container with enum?
    std::fixed << std::setprecision(4) << (float)(after - before) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
    return 0;
}