#include "Iter.hpp"

int main()
{
    // int ar[3] = {3, 5, 2};
    double arr[3] = {3.2, 5.1, 2.4};
    ::iter(arr, 3, ::multiply<double>); //casting type to template, doest it have to be the same as array content?
    std::cout << arr[0] << " " << arr[1] << " " << arr[2] << std::endl;
    return 0;
}