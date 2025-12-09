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
    //would copy only Child specific members. Rest is copied automatically.
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) //no chaining
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);    //!!!! used operator which belongs to ClapTrap class
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "ScavTrap " << this->_name << " causing " 
        << this->_attackDamage << " points of damage to " << target << std::endl;
        this->_energyPoints = this->_energyPoints - 1;
    }
    else
        std::cout << "Not enough energy or dead" << std::endl;
}

// void ScavTrap::takeDamage(unsigned int amount)
// {
//     if (this->_hitPoints > 0)
//     {
//         std::cout << "ScavTrap " << this->_name << " was hit with " 
//         << amount << " points of damage" << std::endl;
//         this->_hitPoints = this->_hitPoints - amount;
//     }
//     else
//         std::cout << "Attacked object is already dead" << std::endl;
// }
// void ScavTrap::beRepaired(unsigned int amount)
// {
//     if (this->_hitPoints > 0 && this->_energyPoints > 0)
//     {
//         std::cout << "ScavTrap " << this->_name << 
//             " repairs itself with " << amount << " points" << std::endl;
//         this->_hitPoints = this->_hitPoints + amount;
//         this->_energyPoints = this->_energyPoints - 1;
//     }
//     else
//         std::cout << "Not enough energy or dead" << std::endl;
// }

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap desctructor called" << std::endl;
}

