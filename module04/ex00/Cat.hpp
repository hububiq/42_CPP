#ifndef CAT_H
# define CAT_H
# include "Animal.hpp"

class Cat: public Animal
{
	protected: 
		std::string _type;
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		virtual ~Cat();
		
	virtual void makeSound();
	virtual void getType();
};

#endif
