#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Phonebook.Class.hpp"
#include "Contact.class.hpp"

int main()
{
    PhoneBook       phonebook;
    int             counter = 0;
    
    while (1)
    {
        std::cout << "Type ADD to add new contact, SEARCH to look up the list "
                  << "or EXIT to leave the program and lost your contacts forever!" << std::endl;
        std::string cmnd;
        std::cin >> cmnd;
        if (cmnd == "ADD")
        {
            phonebook.addNew(counter); //what if the user gives empty input? - its resolved by cin specific
            counter++;
            if (counter > 7)
            {
                phonebook.full = true;
                counter = 0;
            }
        }
        else if (cmnd == "SEARCH")
        {
            if (counter == 0 && phonebook.full == false)
                std::cout << "There is no contacts yet in your Phonebook" << std::endl;
            else
            {
                if (!phonebook.full)
                    phonebook.showColumns(counter);
                else
                    phonebook.showColumns(8);
                std::cout << "Choose which contact you want to view --- index from first column" << std::endl;
                int position = 0;
                std::cin >> position;
                if (position > counter - 1)
                    std::cout << "You have no contact under this index" << std::endl;
                else
                    phonebook.showContact(position);
            }
        }
        else if (cmnd == "EXIT")
            std::exit(0);
    }
    return 0;
}

