#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP
# include <fstream>  //includes fstream, ofstream, ifstream, all.
# include <string>
# include "AForm.hpp"
# include <exception>

class ShrubberyCreationForm: public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		// std::string getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExecGrade() const;
		// void beSigned(Bureaucrat& other);

		std::string getTarget();
		void execute(Bureaucrat const& executor) const; //returning fstream is no-go. just void.
};

//	add getter for _target

#endif