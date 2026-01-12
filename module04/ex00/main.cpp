#include "Animal.hpp"

int main()
{
	Animal* a;

	a = new Animal();
	a->makeSound();
	delete a;
	return 0;
}