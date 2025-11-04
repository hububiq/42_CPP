#include <iostream>
#include "Contact.class.hpp"

Contact::Contact()
:   index(0),
    firstName(""),
    lastName(""),
    nickname(""),
    phoneNumber(""),
    darkestSecret("")
{
    return ;
}

Contact::~Contact()
{
    return ;
}
