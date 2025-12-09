#include "FragTrap.hpp"

int main()
{
    ClapTrap f("ostatni");
    ScavTrap d("Skaw");
    FragTrap a("Tkowalsk");
    FragTrap b("Lolek");
    FragTrap c(b);

    a.takeDamage(40);
    a.takeDamage(40);
    a.takeDamage(40);
    a.takeDamage(40);
    a.attack("Bonker");
    d.attack("Bonker2");
    f.attack("Bonker3");
    a.highFivesGuys();
    d.guardGate();
    f = b;
    f.attack("Bonkers3");

    return 0;
}