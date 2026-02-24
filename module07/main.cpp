#include "Whatever.hpp"

int main()
{
    float x = 4.2f;
    float y = 2.1f;
    std::string c = "chain1";
    std::string d = "chain2";
    ::swap(c, d);
    std::cout << c << " " << d << std::endl;
    std::cout << ::max(c, d) << std::endl;
    std::cout << ::min(c, d) << std::endl;
    return 0;
}