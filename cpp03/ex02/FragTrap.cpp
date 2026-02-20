#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    std::cout<<"FragTrap Default Constructor is called"<<std::endl;
    this->hit_p=100;
    this->energy_p=100;
    this->attack_d=30;
}
FragTrap::FragTrap(std::string str):ClapTrap(str)
{
    this->hit_p=100;
    this->energy_p=100;
    this->attack_d=30;
    std::cout<<"FragTrap Constructor for the name called "<< name<<std::endl;
}
FragTrap::FragTrap(const FragTrap &other):ClapTrap(other)
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap& other){
    std::cout << "FragTrap Copy assignment is called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

FragTrap:: ~FragTrap()
{
    std::cout << "FragTrap Destructor for " << name << " called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap "<< name << "highFivesGuys" << std::endl;
}