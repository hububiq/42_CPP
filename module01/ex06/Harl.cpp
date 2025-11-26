#include "Harl.hpp"

/*this double endl funny though*/

Harl::Harl() {}

void Harl::_debug()
{
    std::cout << "I love having extra bacon for" <<
        "my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::_info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put" <<
            "enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void Harl::_warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for" <<
                "years, whereas you started working here just last month" << std::endl << std::endl;
}
void Harl::_error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::callFunction(int i)
{
    void (Harl::*ptrArray[])() = 
    {
        &Harl::_debug,    //taking addresses of each member function in class.
        &Harl::_info,
        &Harl::_warning,
        &Harl::_error
    };
    (this->*ptrArray[i])();
}

Harl::~Harl() {}