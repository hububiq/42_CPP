#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <string>
# include "Array.tpp"

template <typename T>
class Array 
{
    private:
        T* _array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);

        ~Array();

};

#endif