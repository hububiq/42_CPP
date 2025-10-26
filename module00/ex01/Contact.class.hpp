#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
# include <string>

class Contact
{
    public:
        int         index;
        std::string firstName;
        std::string lastName;
        std::string nickname;
        int         phoneNumber;
        std::string darkestSecret;

        Contact();
        ~Contact();
};

#endif