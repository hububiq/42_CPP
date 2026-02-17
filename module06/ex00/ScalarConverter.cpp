#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string str)
{
    try
    {
        if (str.length() == 1 && !std::isdigit(str[0]))
        {
            if (str[0] < 32)
                std::cout << "Non displayable" << std::endl;
            else
            {
                std::cout << "char: " << str[0] << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: impossible" << std::endl;
                std::cout << "double: impossible" << std::endl;
            }
        }
        else 
        {
            std::cout << std::fixed << std::setprecision(1);
            if (int temp = std::stoi(str))
            {
                std::cout << "char: " << static_cast<char>(temp) << std::endl;
                std::cout << "int: " << temp << std::endl;
                std::cout << "float: " << static_cast<float>(temp) << "f" << std::endl;
                std::cout << "double: " << static_cast<double>(temp) << std::endl;
            }
            else if (int temp = std::stod(str))/* || (int temp = std::stof(str))*/
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: " << static_cast<int>(temp) << std::endl;
                std::cout << "float: " << static_cast<float>(temp) << "f" << std::endl;
                std::cout << "double: " << temp << std::endl;
            }
            else if (int temp = std::stof(str))
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: " << static_cast<int>(temp) << std::endl;
                std::cout << "float: " << static_cast<float>(temp) << "f" << std::endl;
                std::cout << "double: " << temp << std::endl;
            }
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}