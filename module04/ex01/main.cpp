#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* 
   This exercise showing the concept of Composition.
   Animals array belongs to main but Brain objects belong to Animals (Dog, Cat). 
   Big takeaway is also that: str::string objects dont require deep copy, C++ handles it automatically. 
   Only objects with content like pointers require deep to not let the double free happen.
   Main deletes and deconstructors deletes are done separately.
   At the end --- delete [] arr is not enough. it only deletes stack array, not content allocated with "new"
*/

/*
	order of creation: 
	Animal -> Dog -> Brain  ----- Brain() is happening in the body of constructor 
	Animal -> Brain -> Dog  -----   if it was in initialisaton list

	order of deconstruction
	Dog -> Brain -> Animal  ----- delete _brain is in Dog deconstructor, therefore it appears first.
*/

int main()
{
	const Animal* arr[20];

	for (int i = 0; i < 10; i++)
		arr[i] = new Dog();
	for (int i = 10; i < 20; i++)
		arr[i] = new Cat();
	for (int i = 0; i < 20; i++)
		delete arr[i];
	std::cout << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	Dog k;
	Dog d(k);
	k = d;

	delete j;
	delete i;
	return 0;
}