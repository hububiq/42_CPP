#include "Bureaucrat.hpp"
#include <ostream>

/*TO DO
-problems with overriding what(). printing error message from std::exception
-bad implementation of insertion overload*/
int main()
{
	Bureaucrat b;
	Bureaucrat c(b);
	Bureaucrat d = c;

	std::cout << b.getName() << std::endl;
	std::cout << c.getName() << std::endl;
	std::cout << d.getName() << std::endl;

	//Bureaucrat e(200);
	//Bureaucrat f(150);
	try
	{
		Bureaucrat f(150);
		std::cout << f.getName() << std::endl;
		f.setGrade(160);
		std::cout << f.getGrade() << std::endl;
		f.decrGrade();
		std::cout << f.getGrade() << std::endl;
		if (f.getGrade() > 150 || f.getGrade() < 1)
			throw(Bureaucrat::MyException::exception());
	}
	catch (Bureaucrat::MyException::exception& e)
	{
		std::cout << "bababa " << e.what() << "--Kupa--------" << std::endl;
	}

};