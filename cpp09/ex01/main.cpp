#include "RPN.hpp"

int main(int argc,char **argv)
{
    if (argc != 2)
    {
        std::cerr<<"Error wrong arguments number";
        return(1);
    }
    RPN P;
    std::string input = argv[1];
    P.counter(input);
    
}