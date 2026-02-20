#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("defaultclap_name"),ScavTrap(),FragTrap(),name("default")
{
    std::cout<<"DiamondTrap Default Constructor called"<<std::endl;
    this->hit_p=FragTrap::hit_p;
    this->energy_p=ScavTrap::energy_p;
    this->attack_d=FragTrap::attack_d;
}
DiamondTrap::DiamondTrap(std::string str):ClapTrap(str + "_clap_name"),ScavTrap(str),FragTrap(str),name(str)
{
    this->hit_p=FragTrap::hit_p;
    this->energy_p=ScavTrap::energy_p;
    this->attack_d=FragTrap::attack_d;
    std::cout<<"DiamondTrap Constructor for the name called "<< name<<std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &other):ClapTrap(other),ScavTrap(other),FragTrap(other),name(other.name)
{
    std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}
DiamondTrap:: ~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor for " << name << " called" << std::endl;
}
DiamondTrap DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap Copy assignment is called" << std::endl;
    if(this==&other)
    {
        return(*this);
    }
        this->name=other.name;
        this->attack_d=other.attack_d;
        this->energy_p=other.energy_p;
        this->hit_p=other.hit_p;
        return (*this);
}
void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << " I am a DiamondTrap named " << this->name <<
	" and I am  ClapTrap named " << ClapTrap::name <<std::endl;
}