#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        std::cerr<<"Error\n";
        return (1);
    }
    try
    {
            PmergeMe P(argc,argv);
            P.run();
    }
    catch(...)
    {}
    
}