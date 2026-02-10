#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
	AForm(), 
	_target(target),
	_signGrade(145),
	_execGrade(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other):
	AForm(),
	_name(other._name),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade)
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

// std::string ShrubberyCreationForm::getName() const
// {
// 	return this->_name;
// }

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

//

std::string ShrubberyCreationForm::getTarget()
{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	try
	{
		if (this->getSignGrade() >= executor.getGrade() && this->getExecGrade() >= this->getGrade() && this->getSign() == true)
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
		}
		else
			throw ShrubberyCreationForm::GradeTooLowException();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl; 
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
