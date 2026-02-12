#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other): AForm(other)
{
	this->_target = other._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return *this;
}

void PresidentialPardonForm::setTarget(std::string target)
{
	this->_target = target;
}

std::string PresidentialPardonForm::getTarget()
{
	return this->_target;
}

int PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	try
	{
		if (this->getSign() == false && executor.getGrade() > 150)
			throw PresidentialPardonForm::GradeTooLowException();
		else if (this->getSign() == false && executor.getGrade() < 1)
			throw PresidentialPardonForm::GradeTooHighException();
		else if (this->getSignGrade() >= executor.getGrade() && this->getExecGrade() >= executor.getGrade())
		{
			std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox "
					<< std::endl;
			return 1;
		}
		else
			throw PresidentialPardonForm::GradeTooLowException();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << " to execute. Pardoning failed." << std::endl; 
	}
	return 0;
}

PresidentialPardonForm::~PresidentialPardonForm() {}