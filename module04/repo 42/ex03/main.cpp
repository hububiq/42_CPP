#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();  //child class instantiation with base class type

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice"); //creating clone under the hoo
    me->equip(tmp);				//equiping this clone to Characters inventory. clone() belongs to AMateria
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob); //two-argumented Character function use() is using underneath one-argumented functions from AMateria (cure and ice)
    delete bob;
    delete me;
    delete src;

    return 0;
}