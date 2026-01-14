#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("randomname_butwrong")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->_type = other._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void WrongAnimal::makeSound()
{
	std::cout << "Making undefined WrongAnimal sound" << std::endl;
}

void WrongAnimal::getType()
{
	std::cout << this->_type << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}