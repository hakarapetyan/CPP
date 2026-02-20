#include "Zombie.hpp"

Zombie::Zombie()
{
    this->name="Zombie does not have a name ";
}
Zombie::Zombie(std::string name)
{
    std::cout << this -> name << " was created." << std::endl;
    this->name=name;
}
Zombie::~Zombie()
{
    std::cout<<this->name<<": unfortunattely,we lost the zombie"<<std::endl;
}
void Zombie::announce(void)
{
        std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
void Zombie::set_name(std::string name)
{
    this->name=name;
}
