#include "Bureaucrat.hpp"
#include <ostream>

int main()
{
	// Bureaucrat b;
	// Bureaucrat c(b);
	// Bureaucrat d = c;

	// std::cout << b.getName() << std::endl;
	// std::cout << c.getName() << std::endl;
	// std::cout << d.getName() << std::endl;

	std::cout << "Checking argumented construtor:" << std::endl; 
	Bureaucrat e(200);
	Bureaucrat f(2);
	f.incrGrade();
	std::cout << "\nChecking grade getter" << std::endl;
	std::cout << "Grade value is: " << f.getGrade() << std::endl;
	std::cout << "\nChecking grade setter" << std::endl;
	f.setGrade(-2);
	std::cout << "\nChecking insertion overload" << std::endl;
	std::cout << f;
	std::cout << e;
};