#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice& other): AMateria(other) {}

Ice& Ice::operator=(const Ice& other)
{
    (void)other;
    return *this;
}

AMateria* Ice::clone() const
{
    AMateria* cl = NULL;
	cl = new Ice();
    return cl;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots and ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice() {}