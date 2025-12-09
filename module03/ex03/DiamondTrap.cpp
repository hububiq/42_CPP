#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap default constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name):
    ClapTrap(name + "_clap_name"),                  //must call parametrized constr, otherwise default constructor is called. only grandchild can construct base class.
    ScavTrap(name),
    FragTrap(name)
{                                                   //constructing in the body, because the scope of DiamonTrap runs last, so we make it independent from other classes' construction order in class DiamondTrap
    this->_name = name;
    ClapTrap::_name = name + "_clap_name";          //reapplication of the suffix because other classes overwriting to just a "name".
    this->_hitPoints = FragTrap::_hitPoints;        //with classnames:: because they variables members are shadowed
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "Argumented DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):
    ClapTrap(other),
    ScavTrap(other),
    FragTrap(other)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamonTrap copy assignment operator is called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "This is DiamondTrap name: " << this->_name << " and ClapTrap name: " 
                << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor is called" << std::endl;
}





/*when class is child and has parent, by constructing it automatically default constructor of grandparent class is called.
to explicitly call parametrized constructor, it need to be called in grandchildren class.
calling grandparent constructor is only allowed with 'virtual' keyword on parents.

to sum up: diamon will have special ability to call claptrap constructor directly, 
then base class construction for the middle parents is skipped*/

/*naming will be inherited with suffix - concantenated in initialisation list - its mandatory to initialise it manually because of virtuals classes*/

/*names are shadowed, need :: to distinguish them with Class name*/

/*flag -Wshadow will let compile with the same variable name in the nested class, basically it is mistake
and -Wno-shadow is used to prevent it*/