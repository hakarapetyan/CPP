#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i = 0;
    if (N <= 0)
        return (nullptr);
    Zombie *zomb = new Zombie[N];
    while (i < N)
    {
        zomb[i].set_name(name);
        i++;
    }
    return (zomb);
}