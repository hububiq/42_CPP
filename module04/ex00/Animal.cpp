#include "Animal.hpp"

Animal::Animal(): _type("randomname")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_type = other._type;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void Animal::makeSound()
{
	std::cout << "Making undefined animal sound" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}