#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "Phonebook.Class.hpp"

//obiekty widzą siebie nawzajem!!! 
//w main jak instancjonuje obiekt danej klasy, to odwoluje sie juz tylko do niego, nie do klasy np PhoneBook::
//definicja konstruktora i destruktora, ktore musza nazywac sie tak samo jak klasa.
//definicje funkcji 

PhoneBook::PhoneBook()
:   full(false)
{
    return ;
}

void PhoneBook::addNew(int index_from_main)
{
    this->contacts[index_from_main].index = index_from_main;
    std::cout << "Please input your name" << std::endl;
    std::cin >> this->contacts[index_from_main].firstName;
    std::cout << "Please input your last name" << std::endl;
    std::cin >> this->contacts[index_from_main].lastName;
    std::cout << "Please input your nickname" << std::endl;
    std::cin >> this->contacts[index_from_main].nickname;
    std::cout << "Please enter your number (digits only)" << std::endl;
    std::cin >> this->contacts[index_from_main].phoneNumber;
    std::cout << "Please input your darkest secret" << std::endl;
    std::cin >> this->contacts[index_from_main].darkestSecret;
    return ;
}

void PhoneBook::showColumns(int counter)
{
    for (int i = 0; i < counter; i++)
    {
        std::cout << std::setfill(' ') << std::setw(10);
        std::cout << this->contacts[i].index << "|";
        std::cout << std::setfill(' ') << std::setw(10);
        if (this->contacts[i].firstName.length() > 10)
            std::cout << this->contacts[i].firstName.substr(0, 10) << "|";
        else
            std::cout << this->contacts[i].firstName << "|";
        std::cout << std::setfill(' ') << std::setw(10);
        if (this->contacts[i].lastName.length() > 10)
            std::cout << this->contacts[i].lastName.substr(0, 10) << "|";
        else
            std::cout << this->contacts[i].lastName << "|";
        std::cout << std::setfill(' ') << std::setw(10);
        if (this->contacts[i].nickname.length() > 10)
            std::cout << this->contacts[i].nickname.substr(0, 10) << "|" << std::endl;
        else
            std::cout << this->contacts[i].nickname << "|" << std::endl;
    }
}

void PhoneBook::showContact(int position)
{
    if (position >= 0 && position <= 7)
    {
        std::cout << "Name: " << this->contacts[position].firstName << std::endl;
        std::cout << "Last name: " << this->contacts[position].lastName << std::endl;
        std::cout << "Nickname: " << this->contacts[position].nickname << std::endl;
        std::cout << "Number: " << this->contacts[position].phoneNumber << std::endl;
        std::cout << "Darkest secret: " << this->contacts[position].darkestSecret << std::endl;
    }
    else 
        std::cout << "You chose the wrong index." << std::endl;
}

PhoneBook::~PhoneBook( void )
{
    return ;
}