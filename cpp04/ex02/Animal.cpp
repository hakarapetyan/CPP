#include "Animal.hpp"

Animal::Animal(): type("animal")
{
    std::cout<<"Animal default constructor called"<<std::endl;
}

Animal ::Animal(const Animal &other)
{
    this->type=other.type;
    std::cout<<"Animal copy constructor called"<<std::endl;
}

Animal& Animal :: operator=(const Animal &other)
{
    std::cout<<"Animal assignation operator called"<<std::endl;
    if(this==&other)
    {
        return(*this);
    }
    this->type=other.type;
    return(*this);
}

Animal::~Animal()
{
    std::cout<<"Animal destructor called"<<std::endl;
}

void Animal :: makeSound() const
{
    std::cout<<"animals don’t bark"<<std::endl;
}

std::string Animal :: getType() const
{
    return(this->type);
}