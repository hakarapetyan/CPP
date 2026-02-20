#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* form ;

    try
    {
        form = someRandomIntern.makeForm("RobotomyRequestForm","Bender");
        if (form)
        {
            std::cout << *form << std::endl;
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        form = someRandomIntern.makeForm("ShrubberyCreationForm","Garden");
        if (form)
        {
            std::cout << *form << std::endl;
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        form = someRandomIntern.makeForm("PresidentialPardonForm", "Alice");
        if (form)
        {
            std::cout << *form << std::endl;
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        form = someRandomIntern.makeForm("unknown form", "Nobody");
        if (form)
        {
            std::cout << *form << std::endl;
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Intern couldn’t create the form: " << e.what() << std::endl;
    }

    return 0;
}




