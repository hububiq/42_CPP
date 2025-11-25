#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType): _type(weaponType) {}

std::string const & Weapon::getType()
{
    return (this->_type);
}

void Weapon::setType(std::string otherType)
{
    this->_type = otherType;
}

Weapon::~Weapon() {}