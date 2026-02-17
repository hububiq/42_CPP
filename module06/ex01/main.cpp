#include "Serializer.hpp"

/*
    search about uintptr_t type more,
*/

int main()
{
    Data* b = new Data;
    b->nb = 5;
    uintptr_t temp1;
    Data* temp2;

    temp1 = Serializer::serialize(b);
    temp2 = Serializer::deserialize(temp1);

    std::cout << b << std::endl;
    std::cout << temp2 << std::endl;
    delete b;
    if (b == temp2)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    return 0;
}