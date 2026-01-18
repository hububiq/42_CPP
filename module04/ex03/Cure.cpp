#include "Cure.hpp"

Cure::Cure() {}

Cure::Cure(std::string const& type)  // do they mean this by setting type with lowercase?
{
    this->_type = type;
}

Cure::Cure(const Cure& other): AMateria(other)
{
    this->_type = other._type;
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
        this->_type = other._type;
    return *this;
}

Cure::~Cure() {}