#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("randomname")
{
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->_type = other._type;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void AAnimal::makeSound()
{
	std::cout << "Making undefined animal sound" << std::endl;
}

void AAnimal::getType()
{
	std::cout << this->_type << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}