#include "Zombie.hpp"

Zombie::Zombie()
{
    this->name="Zombie do not have a name ";
}
Zombie::Zombie(std::string name):name(name)
{
    std::cout << this -> name << " Zombie was created." << std::endl;
}
Zombie::~Zombie()
{
    std::cout<<this->name<<": unfortunattely,we lost the zombie"<<std::endl;
}
void Zombie::announce(void)
{
        std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
