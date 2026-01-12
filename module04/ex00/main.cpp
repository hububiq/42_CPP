#include "Animal.hpp"
#include "Cat.hpp"

int main()
{
	Animal* a;
	//Animal* b; - without virtual is making undefined sound even if I call Cat() constructor (compiler takes the class type only)
	Animal* b;

	a = new Animal();
	b = new Cat();
	a->makeSound();
	b->makeSound();
	a->getType();
	b->getType();
	delete a;
	delete b;
	return 0;
}