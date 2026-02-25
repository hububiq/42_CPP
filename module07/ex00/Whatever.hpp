#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template <typename T> T max(T x, T y)
{
    return (x > y) ? x : y;
}

template <typename T> T min(T x, T y)
{
    return (x < y) ? x : y;
}

template <typename T> void swap(T& x, T& y)    //reference - to operate on original variables to be able to print them
{
    T temp;

    temp = x;
    x = y;
    y = temp;
}

class Whatever
{
    Whatever();
    Whatever(const Whatever& other);
    Whatever& operator=(const Whatever& other);
    ~Whatever();
};

#endif 