#ifndef HUMANA_H
# define HUMANA_H
# include "Weapon.hpp"

class HumanA
{
    private:
        Weapon&      _weapon; //reference is faster then just copy (no &) copy will not change original object
        std::string _name;
    public:
        void attack();
        std::string getName();
};

#endif