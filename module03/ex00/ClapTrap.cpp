#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}  //default constr mandatory in OCF.

ClapTrap::ClapTrap(const std::string& name): 
    _name(name),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0),
{}

//copy constr


//assignment operator


ClapTrap::~ClapTrap() {}