#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    Base *b;

    b=generate();

    std::cout<<"identify *=";
    identify(b);
    std::cout<<"identify &=";
    identify(*b);

    delete b;

}