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
		unsigned int size() const;
		class OutOfRange: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Array index out of bounds";
				}
		};
		T& operator[](unsigned int index);
};

# include "Array.tpp"
#endif