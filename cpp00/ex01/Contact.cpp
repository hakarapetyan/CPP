#include "Contact.hpp"

Contact :: Contact()
{
    first_name = "";
    return ;}
Contact :: ~Contact()
{return ;}
void Contact :: set_firstname(string str)
{
    this->first_name = str;
} 
void Contact :: set_lastname(string str)
{
    this->last_name = str;
} 
void Contact :: set_nickname(string str)
{
    this->nick_name = str;
} 
void Contact :: set_phonenumber(string str)
{
    this->phone_number = str;
} 
void Contact :: set_darksecret(string str)
{
    this->darkest_secret = str;
} 
string Contact :: get_firstname()
{
    return (this->first_name);
}
string Contact :: get_lastname()
{
    return (this->last_name);
}
string Contact :: get_nickname()
{
    return (this->nick_name);
}
string Contact :: get_phonenumber()
{
    return (this->phone_number);
}
string Contact :: get_darksecret()
{
    return (this->darkest_secret);
}