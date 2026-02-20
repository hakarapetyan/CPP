#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name), wap(weapon) {
}
HumanA::~HumanA()
{}
void HumanA::attack()
{
    std::cout<<this->name<<" attacks with their "<<wap.getType()<<std::endl;
}