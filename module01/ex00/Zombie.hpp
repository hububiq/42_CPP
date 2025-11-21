#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie
{
    private:
        std::string _name;  //on a stack
    public:
        Zombie();
        ~Zombie();

        void announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif 