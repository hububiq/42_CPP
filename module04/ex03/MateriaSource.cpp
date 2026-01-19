#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
        this->_copies[i] = NULL;  //I do NULL because can't to new AMateria(). its abstract!
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i])
                delete this->inventory[i];
        }
        for (int i = 0; i < 4; i++)
            this->_inventory[i] = NULL;
        for (int i = 0; i < 4; i++)
        {
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->_copies[i])
        {
            this->_copies[i] = m;
            return ;
        }
    }
    delete m; //right?? in case full inventory to avoid leak

}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->copies[i] && this->_copies[i]->getType() == type) //need to check if it exists! otherwise segfault.
        {
            return this->_copies[i]->clone(); //returning a clone!!
        }
    }
    return 0;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_copies[i])
            delete this->_copies[i];
    }
}