#ifndef WEAPON_H
# define WEAPON_H
# include <string>

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