#include "Bureaucrat.hpp"

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
		f.decrGrade();
		std::cout << f.getGrade() << std::endl;
		if (f.getGrade() > 150)
			throw(Bureaucrat::MyException::exception());
	}
	catch (Bureaucrat::MyException::exception& e)
	{
		std::cout << "bababa" << e.what() << "--Kupa--------" << std::endl;
	}
};