#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal* a;
	//Animal* b; - without virtual is making undefined sound even if I call Cat() constructor (compiler takes the class type only)
	Animal* b;
	Animal* c;
	WrongAnimal* f;
	WrongAnimal* g;

	a = new Animal();
	b = new Cat();
	c = new Dog();
	std::cout << std::endl; 

	f = new WrongAnimal();
	g = new WrongCat();
	std::cout << std::endl; 
 
	a->makeSound();
	b->makeSound();
	c->makeSound();
	std::cout << std::endl;
	 
	a->getType();
	b->getType();
	c->getType();
	//a(b);
	std::cout << std::endl; 

	f->makeSound();
	g->makeSound();
	f->getType();
	g->getType();
	std::cout << std::endl;

	delete a;	
	delete b;
	delete c;
	delete f;
	delete g;
	return 0;
}