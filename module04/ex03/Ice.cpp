#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice& other): AMateria(other) {}

Ice& Ice::operator=(const Ice& other)
{
    (void)other;
    return *this;
}

AMateria* Ice::clone() const
{
    AMateria* cl = new Ice();
    return cl;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots and ice bolt at " << target.getName() << " *" << std::endl;
}

std::string Ice::getName()
{
    return this->_name;
}

Ice::~Ice() {}