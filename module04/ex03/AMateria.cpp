#include "AMateria.hpp"

/* voiding to keep _type unchanged. because copying ice to cure and vice versa doesnt make sense. it destroy logic. */

AMateria::AMateria() {}

AMateria::AMateria(std::string const& type): _type(type) {}

AMateria::AMateria(const AMateria& other)
{
    (void)other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    (void)other;
    return *this;
}

std::string const& AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}

AMateria::~AMateria() {}