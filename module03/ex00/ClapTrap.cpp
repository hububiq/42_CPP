#include "ClapTrap.hpp"

ClapTrap::ClapTrap() //default constr mandatory in OCF.
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): 
    _name(name),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
{
    std::cout << "Argumented constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " causing " 
        << this->_attackDamage << " points of damage to " << target << std::endl;
        this->_energyPoints = this->_energyPoints - 1;
    }
    else
        std::cout << "Not enough energy or dead" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " was hit with " 
        << amount << " points of damage" << std::endl;
        this->_hitPoints = this->_hitPoints - amount;
    }
    else
        std::cout << "Attacked object is already dead" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << 
            " repairs itself with " << amount << " points" << std::endl;
        this->_hitPoints = this->_hitPoints + amount;
        this->_energyPoints = this->_energyPoints - 1;
    }
    else
        std::cout << "Not enough energy or dead" << std::endl;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "Destructor called" << std::endl;
}