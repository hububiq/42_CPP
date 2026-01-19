#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() {}

Character::Character(std::string& name): _name(name) {}

Character::Character(const Character& other)
{
    this->_name = other._name;
    for(int i = 0; i < 4; i++)
        delete this->_inventory[i];
    for(i = 0; i < 4; i++)
        this->_inventory[i] = other._inventory[i];
}

Character& operator=(const Character* other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for(int i = 0; i < 4; i++)
            delete this->_inventory[i];
        for(int i = 0; i < 4; i++)
            this->_inventory[i] = other._inventory[i];
    }
    return *this;
}

std::string const& Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    for(int i = 0; i < 4; i++)
    {
        if (!this->_inventory[i])
            this->_inventory[i] = m;
    }
}

void Character::unequip(int idx)
{
    if (!this->_inventory[idx])
        return ;
    //create variables and save Materias to them to later deletion by deconstructor.
}

void Character::use(int idx, ICharacter& target)
{

}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
    delete [] this->_inventory;
}