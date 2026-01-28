#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* 
   This exercise showing the concept of Composition.
   Animals array belongs to main but Brain objects belong to Animals (Dog, Cat). 
   I clean in main and deconstructors separately.
   At the end --- delete [] arr is not enough. it only deletes stack array, not content allocated with "new"
*/

int main()
{
	// const Animal* arr[20];

	// for (int i = 0; i < 10; i++)
	// 	arr[i] = new Dog();
	// for (int i = 10; i < 20; i++)
	// 	arr[i] = new Cat();
	// for (int i = 0; i < 20; i++)
	// 	delete arr[i];
	// std::cout << std::endl;

	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// std::cout << std::endl;

	Dog k;
	Dog j(k);

	// delete j;
	// delete i;
	return 0;
}