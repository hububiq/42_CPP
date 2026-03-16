#include "RPN.hpp"

//without operand there is no error output!
//doesnt throw error when there is just one operator in sequence "2 3 + 2 2 + +"
//./RPN "2 e + 2 2 + +"  this sequence entering wrong error clause - No operator provided instead invalid argumencik 

int main(int argc, char **argv)
{
    RPN a;
	std::string arg = argv[1];
	std::stringstream ss(arg); 			//casting continuous characters series
	std::string token;

    if (argc != 2)
	{
        std::cerr << "Error" << std::endl;
	}
	try
	{
		while (ss >> token)
		{
			int sign = 1;
			char ch;
			if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
			{
				try 
				{
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
					}
					else
						throw std::invalid_argument("Error: invalid argumencik");
				}
				catch (std::invalid_argument& e) //will catch from isdigit
				{
					std::cerr << e.what() << std::endl;
					return 1;
				}
			}
			else if (token.size() == 1 && std::string("+-*/").find(token) != std::string::npos)
			{
				// std::cout << "operator faktyczny" << token[0] << std::endl;
				a.executeOperator(token[0]);
			}
			else if (std::string("+-*/").find(token) == std::string::npos)
			{
				std::cout << "Error: No operator provided" << std::endl;
				return 1;
			}
			else 
			{
				std::cerr << "Errordupa" << std::endl;
				return 1;
			}
			std::cout << a.reportStackTop() << std::endl;
		}
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
		return 1; 
	}
    return 0;
}