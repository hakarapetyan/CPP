#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>

class RPN
{
    public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    bool is_operator(const std::string &symb);
    bool is_number(const std::string &symb);
    void counter(std::string &symb);
    private:
    std::stack<int> S;
};
#endif