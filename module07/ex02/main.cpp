#include "Array.hpp"
#include "Array.tpp"

int main()
{
	int* a = new int(); //default init to 0
	std::cout << *a << std::endl;
	Array<int> b(5);
	try
	{
		std::cout << b[0] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	for (int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;
    return 0;
}