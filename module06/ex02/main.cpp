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
	dice_roll = 3; 							//hardcoding random number because it almost certainly generates 1 as first value
	Base * b;
	switch (dice_roll)
	{
		case 1:
		{
			b = new A();
			break;
		}
		case 2:
		{
			b = new B();
			break;
		}
		case 3:
		{
			b = new C();
			break;
		}
	}
	return b;
}

//gonna try to downcasast (horizontal casting)
void identify(Base* p)
{
	std::cout << "\n---identify() with pointers---" << std::endl;
	try
	{
		A* d = dynamic_cast<A *>(p);
		if (d)
			std::cout << "The random type was class A" << std::endl;
		B* e = dynamic_cast<B *>(p);
		if (e)
			std::cout << "The random type was class B" << std::endl;
		C* f = dynamic_cast<C *>(p);
		if (f)
			std::cout << "The random type was class C" << std::endl;
	}
	catch (std::bad_cast& e)
	{
		std::cout << "Dynamic cast failed" << std::endl;
	}
	return ;
}

//catching only reference since can't be NULL-valued. Pointers dont throw error (undefined behaviour)
void identify(Base& p)
{
	std::cout << "\n---identify() with reference---" << std::endl;
	try
	{
		A& g = dynamic_cast<A &>(p);
		if (&g)
			std::cout << "The random type was class A" << std::endl;
	}
	catch (std::bad_cast& e)
	{
		std::cout << "Dynamic cast with class A failed" << std::endl;
	}
	try
	{
		B& h = dynamic_cast<B &>(p);
		if (&h)
			std::cout << "The random type was class B" << std::endl;
	}
	catch (std::bad_cast& e)
	{
		std::cout << "Dynamic cast with class B failed" << std::endl;
	}
	try
	{
		C& i = dynamic_cast<C &>(p);
		if (&i)
			std::cout << "The random type was class C" << std::endl;
	}
	catch (std::bad_cast& e)
	{
		std::cout << "Dynamic cast with class C failed" << std::endl;
	}
	return ;
}

int main()
{
	Base* randomClass = generate();
	Base& randomClassRef = *generate();
	identify(randomClass);
	identify(randomClassRef);
	if (randomClass)
		delete randomClass;
	if (&randomClassRef)
	 	delete &randomClassRef;
	return 0;
}