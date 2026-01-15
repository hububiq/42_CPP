#ifndef WRONGCAT_H
# define WRONGCAT_H
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	protected: 
		std::string _type;
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
		virtual ~WrongCat();
		
	void makeSound() const;
	std::string getType() const;
};

#endif
