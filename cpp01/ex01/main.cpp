#include "Zombie.hpp"

int main()
{
   int i =0;
   int N=4;
   Zombie *z = zombieHorde(N,"Dracula");

   while (i < N)
   {
        z[i].announce();
        i++;
   } 
    delete [] z;
}