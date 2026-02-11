#include "AForm.hpp"

AForm::AForm(): _name("whatever"), _signed(false), _signGrade(0), _execGrade(0) {}

AForm::AForm(std::string name, int signG, int execG): _name(name), _signed(false), _signGrade(signG), _execGrade(execG) {}

AForm::AForm(const AForm& other): 
	_name(other._name),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade)
{
	this->_signed = other._signed;
}

AForm& AForm::operator=(const AForm& other) //ofc no init. objects compared are initialized already//
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSign() const
{
	return this->_signed;
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

int AForm::getExecGrade() const
{
	return this->_execGrade;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

void AForm::beSigned(Bureaucrat& other)
{
	try 
	{
		if (other.getGrade() > this->_signGrade || other.getGrade() > 150) ////FIX LOGIC HERE
			throw AForm::GradeTooLowException();
		else
			this->_signed = true;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const AForm& other)
{
	out << "Getting name info and grades: " << other.getName() << ", "
		<< other.getSign() << ", " << other.getSignGrade() << ", " << other.getExecGrade() << std::endl;
	return out;
}

AForm::~AForm() {}