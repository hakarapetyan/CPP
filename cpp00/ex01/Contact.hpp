#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <iomanip>

typedef std :: string string;

class Contact
{
    public:
    Contact();
    ~Contact();
    void set_firstname(string str);
    void set_lastname(string str);
    void set_nickname(string str);
    void set_darksecret(string str);
    void set_phonenumber(string str);
    string get_firstname();
    string get_lastname();
    string get_nickname();
    string get_darksecret();
    string get_phonenumber();
    private:
    string first_name;
    string last_name;
    string nick_name;
    string darkest_secret;
    string phone_number;

};
#endif