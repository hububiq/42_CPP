#include "Cat.hpp"
#include "AAnimal.hpp"
#include "Brain.hpp"

Cat::Cat(): _type("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_brain = new Brain();
	std::cout << "And Cat's private Brain allocated" << std::endl;
}

Cat::Cat(const Cat& other): AAnimal(other) //do I have to built it manually first? YES, without it its logically broken, only defaultr contructor is called.
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = other._type;
	this->_brain = other._brain;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	*this->_brain = *other._brain;
	return *this;
}

void Cat::makeSound()
{
	std::cout << "Moew meow" << std::endl;
}

void Cat::getType()
{
	std::cout << this->_type << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain; 
}