#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name) {}

/*there is no Weapon"*" here but "&. because in main there is no addres passed but "normal" variable. 
meaning that reference is being sent - therefore Weapon& here in prototype.*/

void HumanB::setWeapon(Weapon& w) 
{
    this->_weapon = &w;                                 //address here on the other hand because I assign to pointer _weapon!
}

void HumanB::attack()
{
    std::string weap = this->_weapon->getType();        //double "->"" because Weapon in this case is a pointer
    std::cout << this->_name << " attacks with their " << weap << std::endl;
}

HumanB::~HumanB() {}