#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <string>
# include <exception>
# include <iostream>
# include <algorithm> //find()

template <typename T> std::ptrdiff_t easyfind(T& container, int val);

# include "easyfind.tpp"

#endif
