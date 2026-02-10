#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other)
{
	this->_target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return *this;
}

//consider which one of belows to (void) and which to adjust
//resolve inaccessibility

std::string ShrubberyCreationForm::getName() const
{
	return this->_name;
}

bool ShrubberyCreationForm::getSign() const
{
	return this->_signed;
}

int ShrubberyCreationForm::getSignGrade() const
{
	return this->_signGrade;
}

int ShrubberyCreationForm::getExecGrade() const
{
	return this->_execGrade;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
