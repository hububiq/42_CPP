#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain deafult constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl; 
	for (int i = 0; i < 100; i++) //copying ideas[100] array. no need to do deep copy, C++ handling automatically
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor called" << std::endl;
}