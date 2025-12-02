#include "Fixed.hpp"

/*all "const" means that the object just made will be read-only!!*/
int main()
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);
    return 0;
}