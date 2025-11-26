#include "Harl.hpp"

int main()
{
    Harl h;
    std::string level;

    while (1)
    {
        std::cout << "Name the level (DEBUG, INFO, WARNING, ERROR): " << std::endl;
        std::cin >> level;
        h.complain(level);
    }
    return 0;
}