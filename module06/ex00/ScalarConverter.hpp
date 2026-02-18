#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include <string>
# include <iostream>
# include <cctype>      //for isdigit to be placed in std:: namespace
# include <limits>      //for infinity
# include <iomanip>     //for display of fractions

/*
    Constructors private - to disallow instantiation
    This class only serves as a container for utility and helper methods

    Static method - belongs to the class, not to the object. Exist independently, can be accessed directly,
    without object. Has access to other static class members.
*/

class ScalarConverter 
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
    public:
        static void convert(std::string str);          
};

#endif