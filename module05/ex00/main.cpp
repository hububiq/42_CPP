#include "Bureaucrat.hpp"
#include <ostream>

/*TO DO
-decrementing shouldn't save value if its inside try{}catch{} exception, shouldnt it
*/
int main()
{
	// Bureaucrat b;
	// Bureaucrat c(b);
	// Bureaucrat d = c;

	// std::cout << b.getName() << std::endl;
	// std::cout << c.getName() << std::endl;
	// std::cout << d.getName() << std::endl;

	//Bureaucrat e(200);
	Bureaucrat f(1);
	f.incrGrade();
		//std::cout << f.getName() << std::endl;
		//f.setGrade(160);
		//std::cout << f.getGrade() << std::endl;
		//f.decrGrade();
		//std::cout << f.getGrade() << std::endl;
	std::cout << "Grade value is: " << f.getGrade() << std::endl;
	//std::cout << f;
};