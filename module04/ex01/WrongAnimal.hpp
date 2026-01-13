#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>

class WrongAnimal 
{
	protected: 
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();		//destructor also needs to be virtual for polymorphism
	
	void makeSound(); 	//virtual for derived objects
	void getType();     //also need virtual. otherwise randomname is printed 
};

#endif 