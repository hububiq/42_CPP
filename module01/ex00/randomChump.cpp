#include <iostream>
#include "Zombie.hpp"

void randomChump( std::string name )
{
   Zombie stackZombie;

   stackZombie.setName(name);
   stackZombie.announce();
   std::cout << "Right now the stack zombie will be destroyed:" << std::endl;
}