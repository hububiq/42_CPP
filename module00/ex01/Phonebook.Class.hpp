#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include "Contact.class.hpp"

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

int isNotString(std::string frominput);
int notAllDigits(std::string number);
#endif 