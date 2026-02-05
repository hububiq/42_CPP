#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include <ostream> 
# include <exception>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
		class MyException: public std::exception
		{
			private:

			public:
				void GradeTooHighException()
				void GradeTooLowException()
				
		};
	public:
		Bureaucrat();
		Bureaucrat(const int& grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string getName();
		int getGrade(int i);
		
		
		void test();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif