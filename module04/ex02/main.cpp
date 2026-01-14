#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* 
   AAnimal* a = new AAnimal();
   trying to instantiate it, compilers withold this action. 
   makeSound = 0; its pure method and class is abstract. 
   nevertheless, children are inheriting operational method. 
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