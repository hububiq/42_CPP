#include <string>
#include <iostream>
#include <cstdlib>
#include "Phonebook.Class.hpp"
#include "Contact.class.hpp"


/*CTRL + D on while(1) is throwing infinite error. cin has status fail, and program its looping on it*/
/*no handling when index is given as non-digit*/

int main()
{
    PhoneBook       phonebook;
    int             counter = 0;
    
    while (1)
    {
        std::cout << "Type ADD to add new contact, SEARCH to look up the list "
                  << "or EXIT to leave the program and lost your contacts forever!" << std::endl;
        std::string cmnd;
        std::getline(std::cin, cmnd);
        if (cmnd.empty())
        {
            std::cout << "You can't input empty line!" << std::endl;
            continue;
        }
        if (cmnd == "ADD")
        {
            if (phonebook.addNew(counter))
                continue;
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
                std::string position;
                std::getline(std::cin, position);
                if (position.empty())
                {
                    std::cout << "You can't input empty line!" << std::endl;
                    continue;
                }
                if (std::stoi(position) < 0 || std::stoi(position) > 7)
                    std::cout << "Index is out of range" << std::endl;
                else if (std::stoi(position) > counter - 1)
                    std::cout << "You have no contact under this index" << std::endl;
                else
                    phonebook.showContact(std::stoi(position));
            }
        }
        else if (cmnd == "EXIT")
            std::exit(0);
    }
    return 0;
}

