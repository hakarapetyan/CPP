#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl H;

    if (argc != 2)
    {
        std::cout<<"invalid number of arguments"<<std::endl;
        return(1);
    }

    H.complain(argv[1]);
}