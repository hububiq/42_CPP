#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Baba"), _grade(1) {}

Bureaucrat::Bureaucrat(int grade): _name("Baba"), _grade(grade)
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
Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade)
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
		if (x > 150 || x < 1)
			throw Bureaucrat::MyException::exception();
		else
			this->_grade = x;
	}
	catch (Bureaucrat::MyException::exception& e)
	{
		std::cout << "Trying to setGrade but: " << e.what() << "-=------Kupa--------" << std::endl;
	}
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
	return "";
}

std::string Bureaucrat::GradeTooLowException()
{
	std::cout << "Grade is below range" << std::endl;
	return "";
}

const char* Bureaucrat::MyException::what() 
{
	std::cout << "This is custom exception" << std::endl;
	return "";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return out;
}

Bureaucrat::~Bureaucrat() {}