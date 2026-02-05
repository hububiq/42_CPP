#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character(): _name("randomname")
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(const std::string& name): _name(name)
{
     for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(const Character& other): _name(other._name)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for(int i = 0; i < 4; i++)
        {
            if (this->_inventory[i])
            {
                delete this->_inventory[i];
                this->_inventory[i] = NULL;
            }
        }
        for(int i = 0; i < 4; i++)
        {
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
            else
                this->_inventory[i] = NULL; // Ensure we copy holes too
        }
    }
    return *this;
}

std::string const& Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
    if (!m)  //always safe check!!!
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (!this->_inventory[i])
        {
            this->_inventory[i] = m;
            return ;
        }
    }
    //when inventory is full. Deletion belongs to main.
    std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
    if (!this->_inventory[idx] || idx < 0 || idx > 3)
        return ;
    //std::string temp_type = this->_inventory[idx]->_type; -- no need tp save it anywhere
    this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3 || !this->_inventory[idx])
        return ;
    this->_inventory[idx]->use(target); //going inside inventory under particular index and using this Materia member function use(). amazin.
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
    //delete [] this->_inventory; illegal here, delete [] is for "new()" operator!
    //not for a static array. allocated with new() I'm deleting in a loop. static array will be deleted by deconstructor.
}