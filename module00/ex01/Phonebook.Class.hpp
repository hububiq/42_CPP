#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include "Contact.class.hpp"

/*entire Contact subclass should be perhaps _private to not let non-member functions change it*/

class PhoneBook
{
    public:
        Contact     contacts[8];
        bool        full;
        PhoneBook();
        ~PhoneBook();

        int addNew(int index_from_main);
        void showColumns(int counter);
        void showContact(int position);
};

int isValid(std::string str, std::string shouldBe);
int isNotString(std::string frominput);
int notAllDigits(std::string number);
#endif 