#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
    private:
    std::string name;
    int hit_p;
    int energy_p;
    int attack_d;
    public:
    ClapTrap();
    ClapTrap(std::string str);
    ClapTrap(const ClapTrap &other);
    ~ClapTrap();
    ClapTrap& operator=(const ClapTrap &other);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
#endif