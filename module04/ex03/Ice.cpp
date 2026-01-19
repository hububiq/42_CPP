#include "Ice.hpp"

Ice::Ice(): _type("ice") {}

Ice::Ice(const Ice& other): AMateria(other)
{
    this->_type = other._type;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
        this->_type = other._type;
    return *this;
}

AMateria* Ice::clone() const
{
    AMateria* cl = new Ice();
    return cl;
    
}

void Ice::use(ICharacter& target) //why do I need target??
{
    std::cout << "* shoots and ice bolt at " << this->getType() << " *" << std::endl;
}

Ice::~Ice() {}