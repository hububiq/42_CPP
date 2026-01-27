#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other): Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;

	this->_type = other._type;

	Brain* brain = new Brain();
	brain = other._brain;
	delete this->_brain;
	this->_brain = other._brain;
	//*this->_brain = *other._brain;
}
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	*this->_brain = *other._brain; //dereferencing to get to the Brain* pointer object.
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor called" << std::endl;
	delete this->_brain;
}