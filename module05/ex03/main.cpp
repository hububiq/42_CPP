#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
   
int main()
{
	Intern k;
	AForm* toObj;
	
	toObj = k.makeForm("Prezidenszl", "Dupachuj");
	if (toObj)
	{
		std::cout << "Target assigned by parameter: " << toObj->getTarget() << std::endl;
		std::cout << toObj->getSignGrade() << std::endl;
		delete toObj;
	}
	return 0;
 };