#include "Fixed.hpp"

//add copy constructor and copy assignment overload

Fixed:: Fixed()
{
	std::cout << "Deafult constructor called" << std::endl;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointNb = value << Fixed::fractionalBits;
}

/*MUST NOT BITSHIFT FLOATS!!!*/
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointNb = roundf(value * (1 << Fixed::fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointNb = other.getRawbits();
	return *this;     //reference is returned - reference is alian for an object. therefore we must dereference pointer to get actual object.
}

int Fixed::getRawbits() const
{
	return this->fixedPointNb;
}

float Fixed::toFloat() const
{
	return (float)this->fixedPointNb / (1 << Fixed::fractionalBits);
}

int Fixed::toInt() const
{
	return this->fixedPointNb >> Fixed::fractionalBits;
}
