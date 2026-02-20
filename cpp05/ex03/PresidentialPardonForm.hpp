#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:
    std::string const target;

    public:
    PresidentialPardonForm();
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &copy);
    PresidentialPardonForm(std::string const target);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
    void execute_action() const;
    std::string const &gettarget() const;
};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& other);
#endif