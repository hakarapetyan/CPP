#include "ClapTrap.hpp"

ClapTrap::ClapTrap():name("default"),hit_p(10),energy_p(10),attack_d(0)
{
    std::cout<<"ClapTrap Default Constructor called"<<std::endl;
}
ClapTrap::ClapTrap(std::string str):name(str),hit_p(10),energy_p(10),attack_d(0)
{
    std::cout<<"ClapTrap Constructor for the name called "<< name<<std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
    this->name=other.name;
    this->attack_d=other.attack_d;
    this->energy_p=other.energy_p;
    this->hit_p=other.hit_p;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTra Copy assignment is called " << std::endl;
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
ClapTrap:: ~ClapTrap()
{
    std::cout << "ClapTrap Destructor for " << name << " called" << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
    if (this->hit_p > 0 && this->energy_p > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_d << " points of damage!" << std::endl;
        this->energy_p--;
    }
    else if(this->energy_p > 0)
        std::cout << "\033[31mClapTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points.\033[0m" << std::endl;
    else
        std::cout << "\033[31mClapTrap " << this->name << " is not able to attack " << target << ", because he has not enough energy points.\033[0m" << std::endl;

}
void ClapTrap:: takeDamage(unsigned int amount)
{
    if(this->hit_p >= (int)amount)
        this->hit_p-=amount;
    else if(this->hit_p > 0 && this->hit_p < (int)amount)
        this->hit_p=0;
    else
    {
        std::cout << "\033[33mClapTrap " << this->name << " is already dead, stop beating it.\033[0m" << std::endl;
        this->hit_p=0;
        return ;
    }
        std::cout << "ClapTrap " << this->name << " was attacked and lost " << amount << " hit points, he now has " << this->hit_p << " hit points." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_p > 0 && this->energy_p > 0)
    {
        this->energy_p--;
        this->hit_p+=amount;
        std::cout << "ClapTrap " << this->name << " repaired itself and gained " << amount << " of hit points, he now has " << this->hit_p << "hit points." << std::endl;
    }
    else if(this->hit_p==0)
        std::cout << "\033[31mClapTrap " << this->name << " is not able to repair itself , because he has not enough hit points.\033[0m" << std::endl;
    else if(this->energy_p==0)
        std::cout << "\033[31mClapTrap " << this->name << " is not able to repair itself , because he has not enough energy points.\033[0m" << std::endl;
}
