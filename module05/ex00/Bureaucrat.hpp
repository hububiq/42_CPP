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
	public:
		class MyException: public std::exception
		{
			const char* what() const throw();
		};
		Bureaucrat();
		Bureaucrat(const int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string GradeTooHighException();
		std::string GradeTooLowException();
		std::string getName() const;
		int getGrade() const;
		void setGrade(int x);
		void incrGrade();
		void decrGrade();

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif