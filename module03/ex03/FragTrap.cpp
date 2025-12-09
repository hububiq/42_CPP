#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Default FragTrap constructor is called" << std::endl;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "Argumented FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) //chaining initialization - must build parent to build child class
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) //no chaining - both objects exist in =, besides functions don't allow init list
{
    std::cout << "FragTrap copy assignment operator is called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "High five guys" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor is called" << std::endl;
}


