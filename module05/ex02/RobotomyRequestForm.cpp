#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other)
{
	this->_target = other._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return *this;
}

//consider which one of belows to (void) and which to adjust
//resolve inaccessibility

// std::string RobotomyRequestForm::getName() const
// {
// 	return this->_name;
// }

bool RobotomyRequestForm::getSign() const
{
	return this->_signed;
}

// int RobotomyRequestForm::getSignGrade() const
// {
// 	return this->_signGrade;
// }

// int RobotomyRequestForm::getExecGrade() const
// {
// 	return this->_execGrade;
// }

RobotomyRequestForm::~RobotomyRequestForm() {}