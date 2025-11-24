#include <iostream>
#include "Zombie.hpp"

//calling constructor is enough to allocate this class' type memory size
//constructor is actually named the same as a Class.
Zombie* newZombie(std::string name)
{
    Zombie* z = new Zombie(); 
    
    z->setName(name);
    z->announce();
    return (z);
}