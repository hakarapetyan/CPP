#include "RPN.hpp"

 RPN::RPN(){}
 RPN::~RPN(){}
 RPN::RPN(const RPN& other)
 {
    this->S=other.S;
 }
 RPN& RPN::operator=(const RPN& other)
 {
    if(this != &other)
        this->S=other.S;
    return *this;
 }
 bool RPN::is_operator(const std::string &symb)
 {
   return(symb=="-" || symb=="+" || symb=="*" ||symb=="/");
 }
 bool RPN::is_number(const std::string &symb)
 {
   if(symb.length() != 1)
   {
      std::cerr<<"Error: number is long\n";
      return false;
   }
   return(symb>="0" && symb <= "9"); 
 }

 void RPN::counter(std::string &input)
 {
   std::stringstream ss(input);
   std::string token;

   while(ss >> token)
   {
      if(is_number(token))
         S.push(token[0] - '0');
      else if(is_operator(token))
      {
         if(S.size() < 2)
         {
            std::cerr<<"Error: wrong input\n";
               return ;
         }
         int b = S.top(); S.pop();
         int a = S.top();S.pop();
         if(token == "+")
            S.push(a+b);
         else if(token == "-")
            S.push(a-b);
         else if(token == "*")
            S.push(a*b);
         else if(token == "/")
         {
            if(b == 0)
            {
               std::cerr << "Error: division by zero" << std::endl;
               return;
            }
               S.push(a/b);
         }
      }
      else
      {
         std::cerr<<"Error: invalid argument\n";
         return ;
      }
   }
   if(S.size() != 1)
   {
      std::cerr<<"Error:\n";
         return ;
   }
   std::cout<<S.top()<<std::endl;
 }
