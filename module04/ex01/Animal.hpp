#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

class Animal 
{
	protected: 
		std::string _type;
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();		//destructor also needs to be virtual for polymorphism
	
	virtual void makeSound(); 	//virtual for derived objects
	virtual void getType();     //also need virtual. otherwise randomname is printed 
};

#endif 