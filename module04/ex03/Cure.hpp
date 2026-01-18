#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure: public AMateria
{
    public:
        Cure();
        Cure(const Cure& other);
        Core& operator=(const Cure& other);
        ~Cure();
};