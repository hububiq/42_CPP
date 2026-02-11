#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* its the best to call base class execute to handle common checks*/
int main()
{
	ShrubberyCreationForm b("Pochlastac sie moznaaaaaa");
	Bureaucrat c;

	std::cout << b.getTarget() << std::endl;
	c.setGrade(160);
	std::cout << c.getGrade() << std::endl;
	c.signForm(b);
	//b.execute(c); creating a f
};

//TO-RESOLVE   signing in spite of too low grade!! Even out of scope of 150.