#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Szrubery", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other): AForm(other)
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

void ShrubberyCreationForm::setTarget(std::string target)
{
	this->_target = target;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

int ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	try
	{
		if (this->getSign() == false && executor.getGrade() > 150)
			throw ShrubberyCreationForm::GradeTooLowException();
		else if (this->getSign() == false && executor.getGrade() < 1)
			throw ShrubberyCreationForm::GradeTooHighException();
		else if (this->getSignGrade() >= executor.getGrade() && this->getExecGrade() >= executor.getGrade())
		{
			std::string filename = this->_target + "_shrubbery";
			std::ofstream out(filename.c_str());  //c_Str() converting to C-style pointer enforced by -std=C++98
			out << "      _     " << std::endl;
			out << "     / \\      " << std::endl;
			out << "    /, ,\\     " << std::endl;
			out << "   /  ,  \\    " << std::endl;
			out << "  /   _  ,\\  " << std::endl;
			out << " / ,/| |\\  \\  " << std::endl;
			out << "/__/ |_| \\__\\ " << std::endl;
			out << "     / \\      " << std::endl;
			out << "    /, ,\\     " << std::endl;
			out << "   /  ,  \\    " << std::endl;
			out << "  /   _  ,\\  " << std::endl;
			out << " / ,/| |\\  \\  " << std::endl;
			out << "/__/ |_| \\__\\ " << std::endl;
			return 1;
		}
		else
			throw ShrubberyCreationForm::GradeTooLowException();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << " to execute." << std::endl; 
	}
	return 0;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
