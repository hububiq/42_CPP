#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string nameArg, Weapon& weaponArg): 
    _name(nameArg), 
    _weapon(weaponArg) {}

std::string HumanA::getName()
{
    return (this->_name);
} 

void HumanA::attack()
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl; //"." because Weapon is just reference. not a pointer
}

HumanA:: ~HumanA() {}