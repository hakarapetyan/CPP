#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <iostream>

class ClapTrap
{
    protected:
    std::string name;
    int hit_p;
    int energy_p;
    int attack_d;
    public:
    ClapTrap();
    ClapTrap(std::string str);
    ClapTrap(const ClapTrap &other);
    virtual ~ClapTrap();
    ClapTrap& operator=(const ClapTrap &other);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
#endif