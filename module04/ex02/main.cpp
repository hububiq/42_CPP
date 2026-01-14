#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* 
   AAnimal* a = new AAnimal();
   trying to instantiate it, compilers withold this action. 
 
   main takeaway from that exercise: if: virtual void makeSound() = 0 - this is pure method. 
   that means class is abstract and cant be instatiated, contrary to inheriting classes.
   they inherit operational method. 
*/

int main()
{
	//AAnimal* a = new AAnimal();
	AAnimal* arr[20];

	for (int i = 0; i < 10; i++)
		arr[i] = new Dog();
	for (int i = 10; i < 20; i++)
		arr[i] = new Cat();
	for (int i = 0; i < 20; i++)
		delete arr[i];
	std::cout << std::endl;

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << std::endl;

	delete j;
	delete i;
	return 0;
}