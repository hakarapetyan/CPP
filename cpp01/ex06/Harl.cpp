#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug( void )
{
    std::cout<<"[ DEBUG ]"<<std::endl;
    std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
    std::cout<<std::endl;
}
void Harl::error( void )
{
    std::cout<<"[ ERROR ]"<<std::endl;
    std::cout<<"This is unacceptable! I want to speak to the manager now.\n";
    std::cout<<std::endl;
}
void Harl::warning( void )
{
    std::cout<<"[ WARNING ]"<<std::endl;
    std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month\n";
    std::cout<<std::endl;
}
void Harl::info( void )
{
    std::cout<<"[ INFO ]"<<std::endl;
    std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
    std::cout<<std::endl;
}


void Harl::complain(std::string level)
{
    int i =0;
    int index = -1;
    std::string lvl[4]={"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*ptr[4])()={
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    while (i < 4)
    {
        if (level == lvl[i])
        {
            index = i;
            break;
        }
        i++;
    }
    switch(index)
    {
        case 0:
            (this->*ptr[0])();
        case 1:
            (this->*ptr[1])();
        case 2:
            (this->*ptr[2])();
        case 3:
            (this->*ptr[3])();
            break;
        default :
            std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
            break;
    }
}