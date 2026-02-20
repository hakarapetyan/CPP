#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon
{
    private:
    std::string type;

    public:
    Weapon();
    Weapon(std::string str);
    ~Weapon();
    const std::string &getType()const;
    void setType(std::string str);
};
#endif