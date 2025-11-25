#ifndef WEAPON_H
# define WEAPON_H
# include <string>

/*do I need to use "const" at the end of for example getType? to tell complier the return is read-only*/

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon(std::string weaponType);
        ~Weapon();

        std::string const & getType();
        void setType(std::string otherType);
};

#endif