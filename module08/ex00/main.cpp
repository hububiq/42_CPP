#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <array>

int main()
{
    std::list<int> li = {2, 4, 5, 6};
    std::deque<int> dek = {2, 5, 3, 6};
    std::vector<int> vc = {5, 3, 1, 7};
    std::array<int, 4> arr = {1, 2, 5, 7};
    std::cout << "Found values under indexes:" << std::endl;
    try {
        std::cout << ::easyfind(vc, 9) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Value is not in container" << std::endl; 
    }
    try {
        std::cout << ::easyfind(li, 4) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Value is not in container" << std::endl; 
    }
    try {
        std::cout << ::easyfind(arr, 7) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Value is not in container" << std::endl; 
    }
    try {
        std::cout << ::easyfind(dek, 5) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Value is not in container" << std::endl; 
    }
    return 0;
}