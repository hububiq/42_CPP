#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* z = new Zombie::Zombie();
    
    this->_name = name;
    //announce();
    return (z);
}