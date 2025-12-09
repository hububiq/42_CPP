#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap a("dodo");
    DiamondTrap b(a);
    //ScavTrap c("skaw");

    DiamondTrap c = b;
    a.attack("lolekmatolek");
    //c.whoAmI();
    a.whoAmI();
    return 0;
}