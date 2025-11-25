#ifndef HUMANA_H
# define HUMANA_H
# include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon&     _weapon; //reference is faster then just copy (copy == no &) copy will not change original object, reference will.
    public:
        HumanA(std::string nameArg, Weapon& weaponArg);
        ~HumanA();

        void attack();
        std::string getName();
};

#endif