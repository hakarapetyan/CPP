#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

template <typename T>
void swap(T &first, T &second)
{
    T tmp;
    tmp = first;
    first = second;
    second = tmp;
}
template <typename Mi>
Mi min(Mi first,Mi second)
{
    if(first == second)
        return(second);
    return((first < second)?first:second);

}

template <typename Ma>
Ma max(Ma first,Ma second)
{
    if(first == second)
        return(second);
    return((first > second)?first:second);

}
#endif