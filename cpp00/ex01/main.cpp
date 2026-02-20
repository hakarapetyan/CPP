#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
    PhoneBook pb;
    string str;

    while(1)
    {
        str = pb.get_input("\033[35mWrite one of the following commands ADD | SEARCH | EXIT\033[37m");

        if(str=="ADD")
          pb.add();
        else if (str == "SEARCH")
            pb.search();
        else if (str == "EXIT")
            break;
        else
            std::cout<<"\033[33mWrong command,hargelis\033[37m"<<std::endl;
    }
    return (0);  

}