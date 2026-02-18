#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>
#include <exception>


Base* generate(void)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,3);
	int dice_roll = distribution(generator);
	std::cout << dice_roll << std::endl;
	dice_roll = 2;
	switch (dice_roll)
	{
		case 1:
		{
			Base* b = new A();
			return b;
		}
		case 2:
		{
			Base* b = new B();
			return b;
		}
		case 3:
		{
			Base* b = new C();
			return b;
		}
	}
}

void identify(Base* p) //gonna try to downcasast (horizontal casting)
{
	try
	{
		A* d = dynamic_cast<A *>(p);
		if (d)
			std::cout << "The random type was class A" << std::endl;
		else
			std::cout << "Cannot cast A" << std::endl;
		B* e = dynamic_cast<B *>(p);
		if (e)
			std::cout << "The random type was class B" << std::endl;
		else
			std::cout << "Cannot cast B" << std::endl;
		C* f = dynamic_cast<C *>(p);
		if (f)
			std::cout << "The random type was class C" << std::endl;
		else
			std::cout << "Cannot cast C" << std::endl;
	}
	catch (std::bad_cast& e) //not catching! casting has undefined behaviour? didn't throw anything but should catch error  ???
	{
		std::cout << "Dynamic cast failed" << std::endl;
	}
	return ;
}

// It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
// inside this function is forbidden
void identify(Base& p)
{}

int main()
{
	// for (int i = 0; i < 1000; i++)
	// {
		Base* randomClass = generate();
		identify(randomClass);
		// if (randomClass)
		// 	delete randomClass;
	// }
	if (randomClass)
		delete randomClass;
	return 0;
}