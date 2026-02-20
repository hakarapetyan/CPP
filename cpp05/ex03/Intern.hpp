#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    
    public:
    Intern();
    ~Intern();
    Intern(const Intern &copy);
    Intern& operator=(const Intern &other);
    AForm *makeForm(std::string form, std::string target);

    class NoSuchForm:public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};

#endif