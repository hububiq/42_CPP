#ifndef WEAPON_H
# define WEAPON_H
# include <string>

/*I could ad const at the end of getType declaration to highlight that this function 
    doesnt alter the class!*/

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon(std::string weaponType);
        ~Weapon();

        std::string const & getType();
        void setType(std::string otherType);
};

#endif