#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include <ostream>
# include <exception>
# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
	public:
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		AForm();
		AForm(int x);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();

		virtual std::string getName() const = 0;
		virtual bool getSign() const = 0;
		virtual int getSignGrade() const = 0;
		virtual int getExecGrade() const = 0;
		virtual void beSigned(Bureaucrat& other) = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& other);

#endif