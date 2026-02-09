#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Baba"), _grade(1) {}

Bureaucrat::Bureaucrat(int grade): _name("Baba"), _grade(0)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else 
			this->_grade = grade;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade)
{
	this->_grade = other._grade; 
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const 
{
	return this->_grade;
}

void Bureaucrat::setGrade(int x)
{
	try
	{
		if (x > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (x < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade = x;
	}
	catch (std::exception& e)
	{
		std::cout << "Trying to setGrade but: " << e.what() << std::endl;
	}
}

void Bureaucrat::incrGrade()
{
	std::cout << "\nTrying to increase" << std::endl;
	try
	{
		int temp = this->_grade;
		if (temp - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade--;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrGrade()
{
	std::cout << "\nTryig to decrease" << std::endl;
	try
	{
		int temp = this->_grade;
		if (temp + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade++;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low ";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << ". " << std::endl;
	return out;
}

Bureaucrat::~Bureaucrat() {}