#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdio>

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
	int size = 6;
	const Animal* arr[size];

	for (int i = 0; i < size / 2; i++)
	{
		printf("%d\n", i);
		arr[i] = new Dog();
	}
	for (int i = (size / 2); i < size; i++)
	{
		printf("%d\n", i);
		arr[i] = new Cat();
	}
	std::cout << arr[2]->getType() << "-------" << std::endl;
	std::cout << arr[4]->getType() << "-------" << std::endl;
	for (int i = 0; i < size; i++)
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