#include <iostream>
#include "Zombie.hpp"

int main()
{
    std::string name;

    std::cout >> "Give the name for zombie";
    std::cin << name;
    Zombie* z = newZombie(name);
    z->announce();
    delete z; //triggers destructor
    return (0);
}