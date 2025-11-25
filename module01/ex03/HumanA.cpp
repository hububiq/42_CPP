#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string nameArg, Weapon& weaponArg): 
    _name(nameArg), 
    _weapon(weaponArg) {}

std::string getName()
{
    return (this->_name);
} 

void attack()
{
    std::cout << this->_name << "attacks with their" << this->_weapon.getType() << std::endl; //not sure what getType() returns -> cout will print ??
}

HumanA:: ~HumanA() {}