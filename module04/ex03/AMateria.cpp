#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const& type): _type(type) {}

AMateria::AMateria(const AMateria& other)
{
    (void)other;
    //this->_type = other._type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    // if (this != &other)
    //     this->_type = other._type;
    (void)other;
    return *this;
}

std::string const& getType() const
{
    return this->_type;
}

void use(ICharacter& target)
{

}

AMateria::~AMateria() {}