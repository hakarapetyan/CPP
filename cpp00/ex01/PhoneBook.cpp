#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->index=0;
}
PhoneBook::~PhoneBook()
{}
string PhoneBook::get_input(string str)
{
    string input;
    std::cout<<str<<": ";
    std::getline(std::cin, input);
    return (input);
}

void PhoneBook::add()
{
    this->contacts[this->index % 8].set_firstname(get_input("First name "));
    this->contacts[this->index % 8].set_lastname(get_input("Last name "));
    this->contacts[this->index % 8].set_nickname(get_input("Nick name "));
    this->contacts[this->index % 8].set_phonenumber(get_input("Phonenumber name "));
    this->contacts[this->index % 8].set_darksecret(get_input("Darkestsecret name "));
    if (ft_isalpha_str(this->contacts[this->index % 8].get_firstname()) && ft_isalpha_str(this->contacts[this->index % 8].get_lastname()) &&
    ft_isdigit_str(this->contacts[this->index % 8].get_phonenumber()) && empty_check(this->contacts[this->index % 8]))
        this->index++;
    else
        std::cout<<"\033[33mWrong input,hargelis,please write the correct input\n\033[37m";
}
void PhoneBook::print_fields()
{
    int i =0;
    string first,last,nick;
    std::cout<<std::setw(10)<<"Index";
    std::cout<<std::setw(2)<<"|";
    std::cout<<std::setw(10)<<"First_name";
    std::cout<<std::setw(2)<<"|";
    std::cout<<std::setw(10)<<"Last_name";
    std::cout<<std::setw(2)<<"|";
    std::cout<<std::setw(10)<<"Nick_name"<<std::endl;
    while (i < 8 && !this->contacts[i].get_firstname().empty())
    {
        first=this->contacts[i].get_firstname();
        last=this->contacts[i].get_lastname();
        nick=this->contacts[i].get_nickname();
        check_length(first,last,nick);
        std::cout<<std::setw(10)<<i;
        std::cout<<std::setw(2)<<"|";
        std::cout<<std::setw(10)<<first;
        std::cout<<std::setw(2)<<"|";
        std::cout<<std::setw(10)<<last;
        std::cout<<std::setw(2)<<"|";
        std::cout<<std::setw(10)<<nick<<std::endl;
        i++;
    } 
    }  

void PhoneBook::contact_print(int index)
{
    std::cout<<"Index: "<<index + 1<<std::endl;
    std::cout<<"First_name: "<<this->contacts[index].get_firstname()<<std::endl;
    std::cout<<"Last_name: "<<this->contacts[index].get_lastname()<<std::endl;
    std::cout<<"Nick_name: "<<this->contacts[index].get_nickname()<<std::endl;
    std::cout<<"Phonenumber: "<<this->contacts[index].get_phonenumber()<<std::endl;
    std::cout<<"Darksecret: "<<this->contacts[index].get_darksecret()<<std::endl;

}
void PhoneBook::search()
{
    string str;
    int index =0;

    print_fields();
    str=get_input("\033[32mWrite only one index(symbol) from the range 0-7\033[0m");
    index = str[0] - '0';
    if (str.length() > 1 || str[0] < '0' || str[0] > '7')
    {
        std::cout<<"\033[33mWrong index,hargelis\033[37m"<<std::endl;
        return ;
    }
    if(this->contacts[index].get_firstname().empty())
    {
        std::cout<<"\033[33mNo contact found at this index,hargelis\033[37m"<<std::endl;
        return ;
    }
    contact_print(index);
    
    return ;

}

int PhoneBook::empty_check(Contact cont)
{
    if (cont.get_firstname().empty() || cont.get_lastname().empty() || cont.get_nickname().empty()
        || cont.get_darksecret().empty() || cont.get_phonenumber().empty())
        return (0);
    return (1);
}
int PhoneBook::ft_isalpha_str(string c)
{
    int i=0;
    while(c[i])
    {
        if ((c[i] < 65 || c[i] > 90) && (c[i] < 97 || c[i] > 122))
            return (0);
            i++;
    }
	return (1);
}
int PhoneBook::ft_isdigit_str(string c)
{
    int i =0;
    while (c[i])
    {
        if (c[i] < 48 || c[i] > 57)
            return (0);
        i++;
    }
	return (1);
}
void PhoneBook::check_length(string &first,string &last, string &nick)
{
        if (first.length()>10)
        first=first.substr(0,9)+'.';
        if (last.length()>10)
        last=last.substr(0,9)+'.';
        if (nick.length()>10)
        nick=nick.substr(0,9)+'.';
}
