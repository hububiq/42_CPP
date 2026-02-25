#include "Iter.hpp"

/* const and non-const is assured with T*/
int main()
{
    const int ar[3] = {3, 5, 2};
    double arr[3] = {3.2, 5.1, 2.4};
    ::iter(arr, 3, ::multiply<double>); //without scope resolution operator also all good. no ambiguity with inubilt funcs.
    std::cout << arr[0] << " " << arr[1] << " " << arr[2] << std::endl;
    ::iter(ar, 3, ::print<const int>);
    return 0;
}