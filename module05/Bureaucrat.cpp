#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Karababa") {}

Bureaucrat::Bureaucrat(const int& grade): 
{
	if (grade < 1)
		throw Bureaucrat::MyException()
	else if (grade > 150)
		throw Bureaucrat::MyException()
		
}
Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name)
{
	this->_grade = other._grade; 
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	//this->_name = other._name;
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

std::string Bureaucrat::getName()
{
	return this->_name;
}

int Bureaucrat::getGrade(int i)
{
	return this->_grade;
}

void Bureaucrat::test()   //with std::except I can't pass message to exception.
{
	try
	{
		if ()
			throw MyException::exception();
	}
	catch (std::exception& a)
	{
		std::cout << a.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat() {}