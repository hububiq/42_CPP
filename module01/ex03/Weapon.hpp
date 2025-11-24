#ifndef WEAPON_H
# define WEAPON_H

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon(st::string weaponType);
        ~Weapon();

        std::string const & getType();
        void setType(std::string otherType);
};

#endif