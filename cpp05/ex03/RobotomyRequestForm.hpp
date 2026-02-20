#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    private:
    std::string const target;

    public:
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    RobotomyRequestForm(std::string const target);
    RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
    void execute_action() const;
    std::string const& gettarget() const;
};

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& other);
#endif