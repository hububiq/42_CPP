#ifndef CAT_HPP
# define CAT_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{
	private:
		Brain* _brain;
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
