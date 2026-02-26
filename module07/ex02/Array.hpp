#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <string>
# include <cstddef>
# include <exception>

template <typename T>
class Array 
{
    private:
        T* 				_array;
        unsigned int 	_size;
    public:
        Array();
        Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
        ~Array();
		T getValue(unsigned int i);
		//size member function
};

# include "Array.tpp"
#endif