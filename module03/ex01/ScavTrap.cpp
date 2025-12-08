#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Deafult ScavTrap constructor called" << std::endl;
}

/*prerequisite construction of ClapTrap with the same name FIRST.
re-initialisation of members with updated values happens IN THE BODY SCOPE*/
ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) 
{
   this->_name = name;
   this->_hitPoints = 100;
   this->_energyPoints = 50;
   this->_attackDamage = 20;
   std::cout << "Argumented ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) //also chaining
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) //no chaining
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);    //!!!! used operator which belongs to ClapTrap class
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap desctructor called" << std::endl;
}

