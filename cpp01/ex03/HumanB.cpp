#include "HumanB.hpp"

HumanB::HumanB(std::string str)
{
    this->name = str;
}   
HumanB::HumanB()
{}
HumanB::~HumanB()
{}
void HumanB::attack()
{
    std::cout<<this->name<<" attacks with their "<<this->wap->getType()<<std::endl;
}
void HumanB::setWeapon(Weapon &weap)
{
    this->wap= &weap;
}