#ifndef HUMANB_H
# define HUMANB_H
# include "iostream"
# include "Weapon.hpp"

/*_weapon is a pointer because it has a null as first value, no initialisation in constructor*/

class HumanB
{
    private:
        std::string     _name;
        Weapon*         _weapon;
    public:
        HumanB(std::string name);
        ~HumanB();

        void setWeapon(Weapon& w);
        void attack();

};

#endif