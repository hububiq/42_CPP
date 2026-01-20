#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include <iostream>
# include "Character.hpp"

class ICharacter;
class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria(std::string const& type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        virtual ~AMateria();
        std::string const& getType() const; //Returns the materia type    no virtual, does exactly the same thing in dervied classes. returns address to the variable (reference) - standard getter behaviour
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif