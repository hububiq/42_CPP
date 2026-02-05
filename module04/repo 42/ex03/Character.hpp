#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

/*  should not include AMateria.hpp to prevent circular dependency.
like: Character needs AMateria, AMateria need ICharacter, ICharacter again needs AMateria. 
only stores pointer AMateria* so it doesnt need the whole picture.
instead we do forward declaration: */

class AMateria;

class Character: public ICharacter
{
    protected:
        std::string _name;
        AMateria* _inventory[4];
    public:
        Character();
        Character(const std::string& _name);
        Character(const Character& other);
        Character& operator=(const Character& other);
		virtual std::string const& getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target); //different than AMateria's use(). separate hierarchical scope 
        virtual ~Character();
};

#endif 