#include "ScavTrap.hpp"

int main()
{
    // ClapTrap a;
    // ClapTrap b("qta");
    // ClapTrap c(a);

    // a.attack("Lol");
    // b.attack("Lol");
    // a = b;
    // b.takeDamage(100);
    // b.takeDamage(100);
    // b.beRepaired(1);

    ScavTrap a;
    ScavTrap b("Tolek");
    ScavTrap c(b);

    c.attack("Victim");
    c.takeDamage(50);
    c.takeDamage(50);
    c.takeDamage(50);
    c.guardGate();

    return 0;
}