#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other) //do I have to built it manually first? YES, without it its logically broken, only defaultr contructor is called.
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->_type = other._type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Moew meow" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}