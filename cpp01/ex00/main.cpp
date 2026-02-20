#include "Zombie.hpp"

int main()
{
    Zombie z;
    z.announce();
    Zombie *zomb = newZombie("Dracula");
    delete zomb;

    randomChump("Biker Girl");
}