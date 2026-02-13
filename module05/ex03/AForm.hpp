#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include <fstream>
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
		AForm(std::string name, int singG, int execG);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm(); //!!

		std::string getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(Bureaucrat& other);

		virtual int execute(Bureaucrat const& executor) const = 0;
		virtual std::string getTarget() const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& other);

#endif