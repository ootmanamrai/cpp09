#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <algorithm>
template <typename T>
typename T::iterator easyfind(T containers, int n)
{
    typename T::iterator it = std::find(containers.begin(), containers.end(), n);
    if(it == containers.end())
        throw std::runtime_error("Couldn't find number\n");
    return (it);
}
#endif