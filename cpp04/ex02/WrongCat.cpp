#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
    type = "Cat";
    std::cout<<"WrongCat default constructor called"<<std::endl;
}

WrongCat ::WrongCat(const WrongCat &other):WrongAnimal(other)
{
    this->type=other.type;
    std::cout<<"WrongCat copy constructor called"<<std::endl;
}

WrongCat& WrongCat :: operator=(const WrongCat &other)
{
    std::cout<<"WrongCat assignation operator called"<<std::endl;
    if(this==&other)
    {
        return(*this);
    }
    this->type=other.type;
    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout<<"WrongCat destructor called"<<std::endl;
}

void WrongCat :: makeSound() const
{
    std::cout<<"WrongCats don’t bark"<<std::endl;
}
