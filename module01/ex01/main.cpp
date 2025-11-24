#include <iostream>
#include "Zombie.hpp"

/*i assumed for every zombie is the same name*/
int main()
{
    int N;
    std::string name;

    std::cout << "Input the number of Zombies you want to create: " << std::endl;
    std::cin >> N;
    std::cout << "And name for Zombies: " << std::endl;
    std::cin >> name;
    Zombie* z = zombieHorde(N, name);
    delete[] z;
    return (0);
}