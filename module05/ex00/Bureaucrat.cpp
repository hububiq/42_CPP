#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Baba") {}

Bureaucrat::Bureaucrat(const int grade)
{
	try
	{
		if (grade < 1)
			throw(Bureaucrat::GradeTooHighException());
		else if (grade > 150)
			throw (Bureaucrat::GradeTooLowException());
	}
	catch (Bureaucrat::MyException::exception& a)
	{
			std::cout << a.what() << std::endl;
	}
		
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

int Bureaucrat::getGrade()
{
	return this->_grade;
}

void Bureaucrat::setGrade(int x)
{
	this->_grade = x;
}

void Bureaucrat::incrGrade()
{
	std::cout << "Increasing" << std::endl;
	this->_grade--;
}

void Bureaucrat::decrGrade()
{
	std::cout << "Decreasing" << std::endl;
	this->_grade++;
}
std::string Bureaucrat::GradeTooHighException()
{
	std::cout << "Grade is above range" << std::endl;
	return "Grade is above range";
}

std::string Bureaucrat::GradeTooLowException()
{
	std::cout << "Grade is below range" << std::endl;
	return "Grade is below range";
}

const char* Bureaucrat::MyException::what() 
{
	std::cout << "This is custom exception" << std::endl;
	return "This is custom exception!";
}

Bureaucrat::~Bureaucrat() {}