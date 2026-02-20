#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
typename T:: iterator easyfind(T &cont, int elem);

class NotFoundException: public std::exception
{
    public:
    const char* what() const throw()
    {
        return("Value not found in container");
    }
};

#include "easyfind.tpp"
#endif