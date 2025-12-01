#include "Fixed.hpp"

Fixed::Fixed(const int value)
{
	this->fixedPointNb = value << Fixed::fractionalBits;
}

/*MUST NOT BITSHIFT FLOATS!!!*/
Fixed::Fixed(const float value)
{
	this->fixedPointNb = roundf(value * (1 << Fixed::fractionalBits));
	//effectively multiplying by 258 is shifting by 8 bits.
	//always to left? what about the right? depenging on what value I wanna get?
	//roundf serves accuracy - floats are inaccurate. 1.999 instead of 2
}

