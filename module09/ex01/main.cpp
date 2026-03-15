#include "RPN.hpp"

int main(int argc, char **argv)
{
    RPN a;

    if (argc != 2)
        std::cerr << "Error" << std::endl;
    if (!std::isdigit(static_cast<unsigned char>(argv[1][0])) &&
        (static_cast<unsigned char>(argv[1][0]) > 9 || static_cast<unsigned char>(argv[1][0]) < 1)) //zle, ujemnych nie obsluguje
        std::cerr << "Error" << std::endl;

    return 0;
}