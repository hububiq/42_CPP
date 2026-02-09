#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include <ostream>
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
	public:
		class GradeTooHighException 
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException
		{
			public:
				virtual const char* what() const throw();
		};
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(Bureaucrat& other);
		void signForm();
};

std::ostream& operator<<(std::ostream& out, const Form& other);

#endif