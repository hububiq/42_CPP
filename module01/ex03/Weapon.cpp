#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType): _type(weaponType) {}

std::string const & getType()
{
    return (this->_type);
}

void setType(std::string otherType)
{
    this->_type = otherType;
}

Weapon::~Weapon() {}