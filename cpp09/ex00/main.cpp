#include "BitcoinExchange.hpp"

int main(int argc,char **argv)
{
    (void)argv;
    if(argc != 2)
    {
        std::cerr<<"Error: could not open file.\n";
        return(1) ;
    }
    try
    {
        BitcoinExchange bit;
        bit.csvloading("data.csv");
        bit.inputprocess(argv[1]);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}