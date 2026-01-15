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
	
	void makeSound() const; 	//virtual for derived objects
	std::string getType() const;    //also need virtual. otherwise randomname is printed 
};

#endif 