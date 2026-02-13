#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string array[3] = {"Szrubery", "Robotomi", "Prezidenszal"};
    int i = 0;
    while (i < 3)
    {
        if (array[i] == name)
        {
            switch(i)
            {
                case 0:
                {
                    AForm* obj = new ShrubberyCreationForm(target);
                    std::cout << "Intern creates " << array[i] << std::endl;
                    return obj;
                }
                case 1:
                {
                    AForm* obj = new RobotomyRequestForm(target);
                    std::cout << "Intern creates " << array[i] << std::endl;
                    return obj;
                }
                case 2:
                {
                    AForm* obj = new PresidentialPardonForm(target);
                    std::cout << "Intern creates " << array[i] << std::endl;
                    return obj;
                }
            }
        }
        i++;
    }
    std::cout << "There is no such form name" << std::endl;
    return NULL;
}

Intern::~Intern() {}