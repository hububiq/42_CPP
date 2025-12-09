#ifndef DIAMONTRAP_H
# define DIAMONDTRAP_H
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap                 //order would matter I guess, If we didnt assign members' values in constructor
{
    private:
        std::string _name;
    public:
        DiamondTrap();
        DiamondTrap(const std::string& name);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        ~DiamondTrap();

        void attack(const std::string& target);
        void whoAmI();
};

#endif