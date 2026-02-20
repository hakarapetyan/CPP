#include <iostream>
#include <ctime>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
    std::cout<<"destructor"<<std::endl;
}
Base * generate(void)
{
    std::srand(std::time(0));

    int i = std::rand() % 3;

    switch (i)
    {
    case 0:
        return new A;
    case 1:
        return new B;
    case 2:
        return new C;
    }
    return(NULL);
}
void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout<<"A"<<std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout<<"B"<<std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout<<"C"<<std::endl;
}
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout<<"A"<<std::endl;
    }
    catch(...){}
     try
    {
        (void)dynamic_cast<B&>(p);
        std::cout<<"B"<<std::endl;
    }
    catch(...){}
     try
    {
        (void)dynamic_cast<C&>(p);
        std::cout<<"C"<<std::endl;
    }
    catch(...){}
    
}