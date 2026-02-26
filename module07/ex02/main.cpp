#include "Array.hpp"
#include "Array.tpp"

int main()
{
	//int* a = new int(); //default init to 
	Array<int> b(4);
	try
	{
		std::cout << b[2] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
    return 0;
}