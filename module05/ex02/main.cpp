#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	ShrubberyCreationForm b("Pochlastac sie mozna");
	Bureaucrat c;

	b.execute(c);
};