#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl h;
    int level;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    if (argc != 2)
    {
        std::cout << "Name exactly one log to view (DEBUG, INFO, WARNING or ERROR)" << std::endl;
        return 1;
    }
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        if (argv[1] == levels[i])
        {
            level = i;
            break;
        }
        if (i == 3)
            level = 5;
    }
    switch (level)
    {
        case 0:
            std::cout << "[ " << argv[1] << " ]" << std::endl;
            h.callFunction(0);
            break;
        case 1:
            std::cout << "[ " << argv[1] << " ]" << std::endl;
            h.callFunction(1);
            break;
        case 2:
            std::cout << "[ " << argv[1] << " ]" << std::endl;
            h.callFunction(2);
            break;
        case 3:
            std::cout << "[ " << argv[1] << " ]" << std::endl;
            h.callFunction(3);
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return 0;
}