#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <string>
# include <cstddef> //size_t

template <typename T> void multiply(T& x)
{
    x = x * 2;
}

template <typename T> void print(T& x)
{
    std::cout << x << std::endl;
}

/* 
-size - hardcoded and passed as const in main, type is known - int. better to use size_t
-2 typenames. F for function 
*/

template <typename T, typename F> void iter(T& arr, size_t const size, F func)
{
    for (size_t i = 0; i < size; i++)
        func(arr[i]);
}

#endif