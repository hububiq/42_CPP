#ifndef ARRAY_TPP
# define ARRAY_TPP
# include "Array.hpp"

template <typename T>
Array<T>::Array() {}

template <typename T>
Array<T>::Array(unsigned int n): _size(n)
{
    this->_array = new T(this->_size);
}

template <typename T>
Array<T>::Array(const Array& other)
{
    this->_size = other._size;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = other.array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        this->_size = other._size;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = other.array[i];
    }
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->_array;
}

template <typename T>
T Array<T>::getValue(unsigned int i)
{
	return this->_array[i];
}

//size member function
#endif