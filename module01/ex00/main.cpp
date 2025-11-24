#include <iostream>
#include "Zombie.hpp"

int main()
{
    std::string name;

    std::cout << "Give the name for zombie" << std::endl;
    std::cin >> name;
    Zombie* z = newZombie(name);
    randomChump(name);
    std::cout << "Below the heap Zombie will be destroyed:" << std::endl;
    delete z; //triggers destructor of pointer
    return (0);
}