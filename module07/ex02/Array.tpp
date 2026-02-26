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
	this->_array = new T[this->_size]();  //() at the end -- init to 0 by default
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = other.array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        this->_size = other._size;
		delete this->_array;
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
unsigned int Array<T>::size() const
{
	return this->_size;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw OutOfRange();
	return this->_array[index];
}

#endif