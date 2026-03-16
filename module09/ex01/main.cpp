#include "RPN.hpp"

int tokenCheck(std::string& token, class RPN& a)
{
	int sign = 1;
	char ch;
	if (token[0] == '-')
	{
		sign = -1;
		ch = token[1];
	}
	else
		ch = token[0];
	if (isdigit(ch))
	{
		int val = (ch - '0') * sign;
		a.pushNumber(val);
		return 1;
	}
	return 0;
}

int main(int argc, char **argv)
{
    RPN a;
	std::string arg = argv[1];
	std::stringstream ss(arg); 							//casting continuous characters series
	std::string token;

    if (argc != 2)
		std::cerr << "Error" << std::endl;
	while (ss >> token)
	{
		if (token.size() > 1 && token[0] != '-')
			return std::cerr << "Error" << std::endl, 1;
		else if (isdigit(token[0]) || (token.size() == 2 && token[0] == '-'))
		{
			if (tokenCheck(token, a))
				continue;
			else
				return std::cerr << "Error" << std::endl, 1;
		}
		else if (token.size() == 1 && std::string("+-*/").find(token) != std::string::npos)
		{
			if (a.executeOperator(token[0]))
				return 1;
		}
		else if (std::string("+-*/").find(token) == std::string::npos || !isdigit(token[0]))
			return std::cerr << "Error" << std::endl, 1;
	}
	if (a.getStackSize() == 1)
		std::cout << a.reportStackTop() << std::endl;
	else
		std::cerr << "Error" << std::endl;
    return 0;
}
