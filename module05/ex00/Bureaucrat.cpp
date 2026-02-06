#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Baba") {}

Bureaucrat::Bureaucrat(const int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
		
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
	this->_grade--;
}

void Bureaucrat::decrGrade()
{
	this->_grade++;
}
void Bureaucrat::GradeTooHighException()
{
	std::cout << "Grade is above range" << std::endl;
}

void Bureaucrat::GradeTooLowException()
{
	std::cout << "Grade is below range" << std::endl;
}

const char* Bureaucrat::MyException::what() 
{
	return "This is custom exception!";
}

Bureaucrat::~Bureaucrat() {}