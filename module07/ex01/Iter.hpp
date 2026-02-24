#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <string>

template <typename T> void multiply(T& x)
{
    x = x * 2;
}

//size - hardcoded and passed as const in main, type is known - int. better to use size_t
//2 typename. F for function
template <typename T, typename F> void iter(T& arr, size_t const size, F func)
{
    for (size_t i = 0; i < size; i++)
        func(arr[i]);
}

#endif