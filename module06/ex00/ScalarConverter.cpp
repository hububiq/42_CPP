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
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] < 32)
            std::cout << "Character not printable" << std::endl;
        std::cout << str[i] << std::endl;
    }
    std::cout << std::stoi(str) << std::endl;

}