#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <ostream>

int main()
{
	Form b;
	std::cout << b;

	Form c(5);
	std::cout << c;

	Bureaucrat a(6);
	std::cout << a;
	b.beSigned(a);
	


};