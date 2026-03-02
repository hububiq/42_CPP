#include "easyfind.hpp"

/* auto type is automatically deducing particular container iterator type */

template <typename T> std::ptrdiff_t easyfind(T& container, int val)
{
    auto it = std::find(container.begin(), container.end(), val);
    if (it == container.end())
        throw std::exception();
    return (std::distance(container.begin(), it));
}
