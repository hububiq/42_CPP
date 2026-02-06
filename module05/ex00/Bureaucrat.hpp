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
			const char* what();
		};
	public:
		Bureaucrat();
		Bureaucrat(const int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		void GradeTooHighException();
		void GradeTooLowException();
		std::string getName();
		int getGrade();
		void setGrade(int x);
		void incrGrade();
		void decrGrade();

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif