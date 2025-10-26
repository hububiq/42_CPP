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

        void addNew(int index_from_main);
        void showColumns(int counter);
        void showContact(int position);
};

#endif 