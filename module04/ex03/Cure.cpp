#include "Cure.hpp"

Cure::Cure(): _type("cure") {}

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

AMateria* Cure::clone() const
{
    AMateria* cl

    cl = new Cure();
    return cl;
    //better to write return Ice(*this) - making photocopy instead of fresh. I dont have attributes to they are the same, otherwise it would reset my attribute to frest start
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << this->getType() << "'s wounds * " << std::endl;
}

Cure::~Cure() {}