#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    std::cout<<"ScavTrap Default Constructor called"<<std::endl;
    this->hit_p=100;
    this->energy_p=50;
    this->attack_d=20;
}
ScavTrap::ScavTrap(std::string str):ClapTrap(str)
{
    this->hit_p=100;
    this->energy_p=50;
    this->attack_d=20;
    std::cout<<"ScavTrap Constructor for the name called "<< name<<std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other)
{
    std::cout << "ScavTrap Copy Constructor is called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap& other){
    std::cout << "ScavTrap Copy assignment is called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}
ScavTrap:: ~ScavTrap()
{
    std::cout << "ScavTrap Destructor for " << name << " called" << std::endl;
}
void ScavTrap::attack(const std::string& target)
{
    if (this->hit_p > 0 && this->energy_p > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_d << " points of damage!" << std::endl;
        this->energy_p--;
    }
    else if(this->energy_p > 0)
        std::cout << "\033[31mScavTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points.\033[0m" << std::endl;
    else
        std::cout << "\033[31mScavTrap " << this->name << " is not able to attack " << target << ", because he has not enough energy points.\033[0m" << std::endl;

}
void ScavTrap::guardGate()
{
    std::cout<<"ScavTrap"<<this->name<<"is now in Gate keeper mode"<<std::endl;
}