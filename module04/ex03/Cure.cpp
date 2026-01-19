#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure& other): AMateria(other) {}

Cure& Cure::operator=(const Cure& other)
{
    (void)other;
    return *this;
}

AMateria* Cure::clone() const
{
    AMateria* cl = NULL;

    cl = new Cure();
    return cl;
    //better to write return Ice(*this) - making photocopy instead of fresh. I dont have attributes to they are the same, otherwise it would reset my attribute to frest start
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds * " << std::endl;
}

std::string Cure::getName()
{
    return this->_name;
}

Cure::~Cure() {}