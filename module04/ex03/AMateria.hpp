#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include <iostream>

class AMateria
{
    protected:
        std::string _type;
    public: //bring up to OCF
        AMateria();
        AMateria(std::string const& type);   //why exactly reference...
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        virtual ~AMateria();
        
        std::string const& getType() const; //Returns the materia type     virtual??
    
    virtual AMateria* clone() const = 0; //both must be in derived class 
    virtual void use(ICharacter& target); // <<<<<< TO IMPLEMENT
};

#endif