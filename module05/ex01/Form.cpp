#include "Form.hpp"

Form::Form(): _name("whatever"), _signed(false), _signGrade(0), _execGrade(0) {}

Form::Form(int x): _name("whatever"), _signed(false), _signGrade(x), _execGrade(0) {}

Form::Form(const Form& other): 
	_name(other._name),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade)
{
	this->_signed = other._signed;
}

Form& Form::operator=(const Form& other) //ofc no init. objects compared are initialized already//
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSign() const
{
	return this->_signed;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecGrade() const
{
	return this->_execGrade;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low ";
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

void Form::beSigned(Bureaucrat& other)
{
	try 
	{
		if (other.getGrade() > this->_signGrade)
			throw Form::GradeTooLowException();
		else
		{
			this->_signed = true;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Form& other)
{
	out << "Getting name info and grades: " << other.getName() << ", "
		<< other.getSign() << ", " << other.getSignGrade() << ", " << other.getExecGrade() << std::endl;
	return out;
}

Form::~Form() {}