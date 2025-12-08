#include "ClapTrap.hpp"

int main()
{
    ClapTrap a;
    ClapTrap b("qta");
    ClapTrap c(a);

    a.attack("Lol");
    b.attack("Lol");
    a = b;
    b.takeDamage(100);
    b.takeDamage(100);
    b.beRepaired(1);
    return 0;
}