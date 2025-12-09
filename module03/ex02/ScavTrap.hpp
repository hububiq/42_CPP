#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();

        void guardGate();
        void attack(const std::string& target);
        //void beRepaired(unsigned int amount); first I overwritten to change the output to ScavTrap
        //void takeDamage(unsigned int amount);
};

#endif 