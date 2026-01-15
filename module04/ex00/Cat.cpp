#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat(): _type("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other) //do I have to built it manually first? YES, without it its logically broken, only defaultr contructor is called.
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = other._type;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Moew meow" << std::endl;
}

std::string Cat::getType() const 
{
	return this->_type; 
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}