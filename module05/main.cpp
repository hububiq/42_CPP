#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b;
	Bureaucrat c(b);
	Bureaucrat d = c;

	std::cout << b.getName() << std::endl;
	std::cout << c.getName() << std::endl;
	std::cout << d.getName() << std::endl;
};