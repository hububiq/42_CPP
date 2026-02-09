#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <ostream>

int main()
{
	Form b;
	std::cout << b;

	Form c(5);
	std::cout << c;

	Bureaucrat a(4);
	std::cout << a;
	c.beSigned(a);
	std::cout << c.getSign() << std::endl;
	a.signForm(c);


};