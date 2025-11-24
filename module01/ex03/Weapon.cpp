#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(): _type(weaponType) {}

std::string const & getType()
{
    return (this->_type);
}

void setType(std::string otherType)
{
    this->_type = otherType;
}

Weapon::~Weapon() {}