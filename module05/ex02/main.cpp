#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* its the best to call base class execute to handle common checks*/
int main()
{
	ShrubberyCreationForm b("Pochlastac sie mozna form");
	Bureaucrat c;

	c.setGrade(130);
	std::cout << c.getGrade() << std::endl;
	c.signForm(b);
	b.execute(c);
};