#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Ice: public AMateria
{
    public:
        Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        ~Ice();

        std::string getName();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif;