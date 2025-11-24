#include <iostream>

int main()
{
    std::string* strPTR;  //lpointer to the string (which is also pointer)

    std::string example = "HI THIS IS BRAIN";
    strPTR = &example;   //saving address to the pointer
    std::string& ref = example;

    std::cout << &example << std::endl;
    std::cout << strPTR << std::endl; //address is in the pointer
    std::cout << &ref << std::endl;

    std::cout << example << std::endl;
    std::cout << *strPTR << std::endl; //going to that address to dereference value
    std::cout << ref << std::endl;
    return (0);
}