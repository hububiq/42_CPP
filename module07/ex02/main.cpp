#include "Array.hpp"
#include "Array.tpp"

int main()
{
	//int* a = new int(); //default init to 0
	Array<int> b(4);
	try
	{
		std::cout << b.getValue(3) << std::endl;
	}
	catch (std::out_of_range& e)
	{
		std::cout << "Index out of range" << std::endl;
	}
    return 0;
}