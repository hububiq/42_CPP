#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* its the best to call base class execute to handle common checks*/
int main()
{
	ShrubberyCreationForm b("Pochlastac sie mozna");
	Bureaucrat c;

	b.execute(c);
};