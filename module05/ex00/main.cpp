#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b;
	Bureaucrat c(b);
	Bureaucrat d = c;

	std::cout << b.getName() << std::endl;
	std::cout << c.getName() << std::endl;
	std::cout << d.getName() << std::endl;

	Bureaucrat e(200);
	Bureaucrat f(148);
	try
	{
		f.decrGrade();
		if (f.getGrade() > 150)
			throw MyException::exception();
	}
	catch (MyException::exception& a)
	{
		std::cout << a.what() << std::endl;
	}
};