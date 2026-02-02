#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

class AAnimal 
{
	protected: 
		std::string _type;
	public:
		AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();		//destructor also needs to be virtual for polymorphism
	
	virtual void makeSound() const = 0; 	//virtual for derived objects
	virtual std::string getType() const;     //also need virtual. otherwise randomname is printed 
};

#endif 