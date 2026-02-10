#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other)
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

//consider which one of belows to (void) and which to adjust
//resolve inaccessibility

std::string PresidentialPardonForm::getName() const
{
	return this->_name;
}

bool PresidentialPardonForm::getSign() const
{
	return this->_signed;
}

int PresidentialPardonForm::getSignGrade() const
{
	return this->_signGrade;
}

int PresidentialPardonForm::getExecGrade() const
{
	return this->_execGrade;
}

PresidentialPardonForm::~PresidentialPardonForm() {}