#include "Weapon.hpp"

Weapon::Weapon()
{}
Weapon::Weapon(std::string str)
{
    this->type=str;
}
Weapon::~Weapon()
{}
const std::string &Weapon::getType()const
{
    return(this->type);
}     
void Weapon::setType(std::string str)
{
     this->type=str;
}