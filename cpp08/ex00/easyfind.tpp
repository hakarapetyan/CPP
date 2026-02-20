#include "easyfind.hpp"
template <typename T>
typename T:: iterator easyfind(T &cont, int elem)
{
    typename T:: iterator it = std::find(cont.begin(),cont.end(),elem);
    if(it == cont.end())
        throw NotFoundException();
    return it;
}