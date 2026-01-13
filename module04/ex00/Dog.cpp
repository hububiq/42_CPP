#include "Dog.hpp"

Dog::Dog(): _type("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = other._type;
}
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void Dog::makeSound()
{
	std::cout << "Woof Woof" << std::endl;
}

void Dog::getType()
{
	std::cout << this->_type << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor called" << std::endl;
}