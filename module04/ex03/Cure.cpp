#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

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
    //better to write return Cure(*this) - making photocopy instead of fresh. I dont have attributes to they are the same, otherwise it would reset my attribute to fresh start
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds * " << std::endl;
}

Cure::~Cure() {}