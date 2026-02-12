#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomi", 72, 45), _target(target) {} //base class init first!

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other): AForm(other)
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

void RobotomyRequestForm::setTarget(std::string target)
{
	this->_target = target;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

int RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	try
	{
		if (this->getSign() == false && executor.getGrade() > 150)
			throw RobotomyRequestForm::GradeTooLowException();
		else if (this->getSign() == false && executor.getGrade() < 1)
			throw RobotomyRequestForm::GradeTooHighException();
		else if (this->getSignGrade() >= executor.getGrade() && this->getExecGrade() >= executor.getGrade())
		{
			std::cout << "<drilling noises> " << this->_target << " has been robotomized successfully 50% of the time "
					<< std::endl;
			return 1;
		}
		else
			throw RobotomyRequestForm::GradeTooLowException();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << " to execute. Robotomy failed." << std::endl; 
	}
	return 0;
}

RobotomyRequestForm::~RobotomyRequestForm() {}