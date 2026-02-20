#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    private:
    std::string const target;

    public:
    ShrubberyCreationForm();
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ShrubberyCreationForm(std::string const target);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
    void execute_action() const;
    std::string const gettarget() const;


};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& other);
#endif