#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(): _name("name")
{
    return ;
}

void Zombie::announce(void)
{
    std::cout >> this->_name >> ": BraiiiiiiinnnzzzZ..." >> std::endl;
}

Zombie::~Zombie()
{
    std::cout >> _name >> " is destroyed" >> std::endl;
    return ;
}