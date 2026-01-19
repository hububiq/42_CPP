#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

/*  should not include AMateria.hpp to prevent circular dependency.
like: Character needs AMateria, AMateria need ICharacter, ICharacter again need AMateria. 
only stores pointer AMateria* so it doesnt need the whole picture.
instead we do forward declaration: */

class AMateria;

class Character: public ICharacter
{
    private:
        std::string _name;
        AMateria* _inventory[4];
    public:
        Character();
        Character(std::string& _name);
        Character(cont Character& other);
        Character& operator=(const Character& other);
        ~Character();
}
#endif 