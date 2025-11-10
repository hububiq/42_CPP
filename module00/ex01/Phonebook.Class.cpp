#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <cctype> //for isdigit
#include "Phonebook.Class.hpp"

//obiekty widzą siebie nawzajem!!! 
//w main jak instancjonuje obiekt danej klasy, to odwoluje sie juz tylko do niego, nie do klasy np PhoneBook::
//definicja konstruktora i destruktora, ktore musza nazywac sie tak samo jak klasa.
//definicje funkcji 
//powinno byc _variables w zakresie private:

PhoneBook::PhoneBook()
:   full(false)
{
    return ;
}

int isNotString(std::string frominput)
{
    size_t i = 0;

    for (i = 0; i < frominput.length(); i++)
    {
        if (isdigit(frominput[i]))
            return (1);
    }
    return (0);
}

int notAllDigits(std::string number)
{
    size_t i = 0;
    
    for (i = 0; i < number.length(); i++)
    {
        if (isdigit(number[i]))
            continue;
        return (1);
    }
    return (0);
}

int PhoneBook::addNew(int index_from_main)
{
    std::string tempFirstName;
    std::string tempLastName;
    std::string tempNickname;
    std::string tempNumber;
    std::string tempDarkestSecret;

    this->contacts[index_from_main].index = index_from_main;
    std::cout << "Please input your name" << std::endl;
    std::getline(std::cin, tempFirstName);
    if (tempFirstName.empty())
    {
        std::cout << "You can't input empty line! Start over." << std::endl;
        return (1);
    }
    if (isNotString(tempFirstName))
    {
        std::cout << "Your name contains digits. Start over." << std::endl;
        return (1);
    }
    this->contacts[index_from_main].firstName = tempFirstName;
    std::cout << "Please input your last name" << std::endl;
    std::getline(std::cin, tempLastName);
    if (tempLastName.empty())
    {
        std::cout << "You can't input empty line! Start over." << std::endl;
        return (1);
    }
    if (isNotString(tempLastName))
    {
        std::cout << "Your last name contains digits. Start over." << std::endl;
        return (1);
    }
    this->contacts[index_from_main].lastName = tempLastName;
    std::cout << "Please input your nickname" << std::endl;
    std::getline(std::cin, tempNickname);
    if (tempNickname.empty())
    {
        std::cout << "You can't input empty line! Start over." << std::endl;
        return (1);
    }
    this->contacts[index_from_main].nickname = tempNickname;
    std::cout << "Please enter your number (digits only)" << std::endl;
    std::getline(std::cin, tempNumber);
    if (tempNumber.empty())
    {
        std::cout << "You can't input empty line! Start over." << std::endl;
        return (1);
    }
    if (notAllDigits(tempNumber))
    {
        std::cout << "Your number contains characters. Start over." << std::endl;
        return (1);
    }
    this->contacts[index_from_main].phoneNumber = tempNumber;
    std::cout << "Please input your darkest secret" << std::endl;
    std::getline(std::cin, tempDarkestSecret);
    if (tempDarkestSecret.empty())
    {
        std::cout << "You can't input empty line! Start over." << std::endl;
        return (1);
    }
    this->contacts[index_from_main].darkestSecret = tempDarkestSecret;
    return (0);
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
            std::cout << this->contacts[i].lastName.substr(0, 9) + "." << ".|";
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