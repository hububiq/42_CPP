#include "Fixed.hpp"

Fixed::Fixed(): fixedPointNb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	//this->fixedPointNb = other.fixedPointNb;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointNb = other.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointNb);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointNb = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}