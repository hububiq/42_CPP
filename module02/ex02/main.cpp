#include "Fixed.hpp"

int main() 
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;                    //value is still here, will vanish after closing bracket
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << Fixed::min(15, 2) << std::endl;    //changing literal integers to temporary objects on the fly (with constructor)
    return 0;
}

/*  if literal value was sent, I do copy and lose possibility to return reference.
    Also: in the subject they ask for fixed-point number in min/max overload
    that obviously means for class object which have the fixed-point number insied
*/