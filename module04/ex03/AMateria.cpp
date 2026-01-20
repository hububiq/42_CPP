#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"

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

// void Character::equip(AMateria* m)
// {
//     if (!m)  //always safe check!!!
//         return ;
//     for (int i = 0; i < 4; i++)
//     {
//         if (!this->_inventory[i])
//         {
//             this->_inventory[i] = m;
//             return ;
//         }
//     }
//     //when inventory is full. Deletion belongs to main.
//     std::cout << "Inventory is full" << std::endl;
// }

// void Character::unequip(int idx)
// {
//     if (!this->_inventory[idx] || idx < 0 || idx > 3)
//         return ;
//     //std::string temp_type = this->_inventory[idx]->_type; -- no need tp save it anywhere
//     this->_inventory[idx] = NULL;
// }

void AMateria::use(ICharacter& target)
{
    (void)target;
}

AMateria::~AMateria() {}