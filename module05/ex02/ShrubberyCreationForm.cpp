#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm()
{
	std::cout << "Creating shrub" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other): AForm()
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

// bool ShrubberyCreationForm::getSign() const
// {
// 	return this->_signed;
// }

// int ShrubberyCreationForm::getSignGrade() const
// {
// 	return this->_signGrade;
// }

// int ShrubberyCreationForm::getExecGrade() const
// {
// 	return this->_execGrade;
// }

//

std::string ShrubberyCreationForm::getTarget()
{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	(void)executor;
	std::string filename = this->_target + "_shrubbery";
	std::ofstream out("filename.txt");
	out << "Kupa dupa." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
