#include "Weapon.hpp"

class HumanB
{
    private:
    std::string name;
    Weapon *wap;
    public:
    HumanB(std::string str);
    HumanB();
    ~HumanB();
    void attack();
    void setWeapon(Weapon &weap);
};