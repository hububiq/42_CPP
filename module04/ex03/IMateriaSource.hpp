#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include <string>

/* light, no variables attributes, separate header
other classes dont know how MateriaSource work. they only know interface
abstraction - without heavy details
interface doesnt have to be in CANONICAL FORM ! no data, just empty functions */

class IMateriaSource 
{
    public:
        virtual ~IMateriaSource() {};
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const& type) = 0;
};

# endif