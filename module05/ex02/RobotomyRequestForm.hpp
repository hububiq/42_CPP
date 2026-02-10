#ifndef ROBOTOMY_REQUEST_FORM.HPP
# define ROBOTOMY_REQUEST_FORM.HPP
# include "AForm.hpp"
# include <string>
# include <exception>

class RobotomyRequestForm: public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(RobotomyRequestForm& other);
		~RobotomyRequestForm();

		std::string getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(Bureaucrat& other);
};

//	adds function making "drilling" noises and try{} catch{} 
//	add getter for _target
#endif