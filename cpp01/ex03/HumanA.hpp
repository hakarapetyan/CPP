#include "Weapon.hpp"

class HumanA
{
    private:
    std::string name;
    Weapon &wap;
    public:
    HumanA(const std::string &str, Weapon &wap);
    ~HumanA();
    void attack();
};