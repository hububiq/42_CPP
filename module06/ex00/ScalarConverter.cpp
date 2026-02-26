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
    if (str == "+inf" || str == "-inf" || str == "nan")
    {
        double d = std::stod(str);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return ;
    }
    if (str == "+inff" || str == "-inff" || str == "nanf")
    {
        float f = std::stof(str);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f)<< std::endl;
        return ;
    }
    try
    {
        if (str.length() == 1 && !std::isdigit(str[0]))
        {
            if (!std::isprint(str[0]))
                std::cout << "Non displayable" << std::endl;
            else
                std::cout << "char: " << str[0] << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        }
        else 
        {
            std::cout << std::fixed << std::setprecision(1);
            if (str.back() == 'f')
            {
                float temp = std::stof(str);
                if (temp > 31 && temp <= 255)
                    std::cout << "char od floata: " << static_cast<char>(temp) << std::endl;
                else
                    std::cout << "char od floata: Non displayable" << std::endl;
                std::cout << "int: " << static_cast<int>(temp) << std::endl;
                std::cout << "float: " << temp << "f" << std::endl;
                std::cout << "double: " << static_cast<double>(temp) << std::endl;
            }
            else if (str.find('.') != std::string::npos)
            {
                double temp = std::stod(str);
                if (temp > 31 && temp <= 255)
                    std::cout << "char od double: " << static_cast<char>(temp) << std::endl;
                else
                    std::cout << "char od double: Non displayable" << std::endl;
                std::cout << "int: " << static_cast<int>(temp) << std::endl;
                std::cout << "float: " << static_cast<float>(temp) << "f" << std::endl;
                std::cout << "double: " << temp << std::endl;
            }
            else
            {
                int temp = std::stoi(str);
                if (temp > 31 && temp <= 255)
                    std::cout << "char od int: " << static_cast<char>(temp) << std::endl;
                else
                    std::cout << "char od int: Non displayable" << std::endl;
                std::cout << "int: " << temp << std::endl;
                std::cout << "float: " << static_cast<float>(temp) << "f" << std::endl;
                std::cout << "double: " << static_cast<double>(temp) << std::endl;
            }
        }
    }
    catch (std::invalid_argument& e)
    {
        std::cout << "impossible - bad argument" << std::endl;
    }
    catch (std::out_of_range& e)
    {
        std::cout << e.what() << "impossible - out of range" << std::endl;
    }
}