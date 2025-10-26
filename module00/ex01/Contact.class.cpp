#include <iostream>
#include "Contact.class.hpp"

Contact::Contact()
:   index(0),
    firstName(""),
    lastName(""),
    nickname(""),
    phoneNumber(0),
    darkestSecret("")
{
    return ;
}

Contact::~Contact()
{
    return ;
}
