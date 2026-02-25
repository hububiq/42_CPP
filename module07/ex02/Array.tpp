#include "Array.hpp"

template <typename T>
Array::Array() {}

template <typename T>
Array::Array(unsigned int n): _size(n)
{
    this->_array = new T(this->_size);
}

template <typename T>
Array::Array(const Array& other)
{
    this->_size = other._size;
    //deep copy of array
}

template <typename T>
Array& Array::operator=(const Array& other)
{
    if (this != &other)
    {
        this->_size = other._size;
        //deep copy of array
    }
}

template <typename T>
Array::~Array() {}

//size