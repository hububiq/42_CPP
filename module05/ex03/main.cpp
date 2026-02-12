#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* -  biggest takeaway: If base class has private attributes and children has no access, need to initialise upon construction
   -  its the best to call base class execute to handle common checks*/
   
int main()
{
	// ShrubberyCreationForm b("home");
	RobotomyRequestForm a("Power_plant");
	// PresidentialPardonForm d("White House");
	 Bureaucrat c;

	//Evaluator must set the grade first. Its initialised to 1.

// 	std::cout << b.getTarget() << std::endl;
	c.setGrade(4);
// 	std::cout << c.getGrade() << std::endl;
	c.signForm(a);
	a.execute(c);
// 	std::cout << b.getSign() << std::endl;
	c.executeForm(a);
	//c.signForm(d);
	// d.execute(c);
	// c.executeForm(d);
 };