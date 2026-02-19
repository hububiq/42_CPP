#include "ScalarConverter.hpp"

//why doesnt work with argv?

int main(int argc, char **argv)
{
	if (!argv[1])
	{
		std::cout << "You need to pass argument" << std::endl;
		return 0;
	}
    ScalarConverter::convert(argv[1]);
    return 0;
}