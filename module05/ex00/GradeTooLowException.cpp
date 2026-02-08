#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is to low ";
}
