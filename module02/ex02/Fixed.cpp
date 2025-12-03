#include "Fixed.hpp"

Fixed::Fixed(): fixedPointNb(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const int value)
{
	this->fixedPointNb = value << Fixed::fractionalBits;
}

/*MUST NOT BITSHIFT FLOATS!!! they dont consist of straight values but stem from formula*/
Fixed::Fixed(const float value)
{
	this->fixedPointNb = roundf(value * (1 << Fixed::fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

/*reference is returned - reference is alias for an object. 
 therefore we must dereference pointer to get actual object.*/

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->fixedPointNb = other.getRawbits();
	return *this;
}

/*CAN'T BELONG TO FIXED CLASS
FIRST ARGUMENT IS AN OUT STREAM. SECOND IS OTHER OBJECT.
OPERATOR OVERLOADS BELONGING TO CLASS HAVE ONE HIDDEN ARGUMENT 'THIS'
AND THE OTHER WHATEVER TYPE, SO ONLY 1 ARGUMENT*/

std::ostream& operator<<(std::ostream& out, const Fixed& src)
{
	out << src.toFloat();
	return out;
}

////////////////////////////////////////////////// ex02

bool Fixed::operator>(const Fixed& other) const
{
	if (this->fixedPointNb > other.fixedPointNb)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed& other) const
{
	if (this->fixedPointNb < other.fixedPointNb)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed& other) const
{
	if (this->fixedPointNb >= other.fixedPointNb)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed& other) const
{
	if (this->fixedPointNb <= other.fixedPointNb)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed& other) const
{
	if (this->fixedPointNb == other.fixedPointNb)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed& other) const
{
	if (this->fixedPointNb != other.fixedPointNb)
		return true;
	return false;
}

/*	need to reverse from fixed point back to normal value (int,float)
	safest to do it IS with float, to prevent destroyed values on float
	it will also handle integer	*/

Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());  //return value Fixed() is using constructor on the fly to create object to be instantly altered inside
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	this->fixedPointNb++;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->fixedPointNb--;
	return *this;
}

/*post in- and decrementation hold special 'int' inside the brackets
 incidacting POST- operation
 no reference in return because it takes copy, add/substract and vanish!
 returns old value - copy. no suitable for chaining */

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;

	this->fixedPointNb++;		//incrementing by 1 is wrong, we operate on bits, not integers
	return temp;                //returning copied object.
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;

	this->fixedPointNb--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	std::cout << "without const" << std::endl;
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	std::cout << "without const" << std::endl;
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::min(Fixed const& a, Fixed const& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::max(Fixed const& a, Fixed const& b)
{
	if (a > b)
		return a;
	return b;
}

//////////////////////////////////////////////// ex02 

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
