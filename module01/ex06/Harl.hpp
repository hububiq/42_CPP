#ifndef HARL_H
# define HARL_H
# include <iostream>

class Harl
{
    private:
        void _debug();
        void _info();
        void _warning();
        void _error();
    public:
        Harl();
        ~Harl();
        void callFunction(int i);
};

#endif