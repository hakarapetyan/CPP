#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern Default Constructor called  "<< std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called  " << std::endl;
}

Intern::Intern (const Intern &other)
{
    *this=other;
    std::cout << "Intern Copy Constructor called  " << std::endl;
}

Intern& Intern::operator=(const Intern &other)
{
    (void)other;
    std::cout << "Intern assignation operator called  " << std::endl;
    return(*this);
}
const char *Intern::NoSuchForm::what() const throw()
{
    return("No Such form\n");
}

 AForm* Intern ::makeForm(std::string form, std::string target)
 {
    int i =0;
    
    std::string forms[]={"ShrubberyCreationForm","RobotomyRequestForm","PresidentialPardonForm"};

    while(i < 3 && form != forms[i])
        i++;

    switch (i)
    {
    case 0:
        std::cout<<"Intern creates "<< "ShrubberyCreationForm"<<std::endl;
        return (new ShrubberyCreationForm(target));
    case 1:
        std::cout<<"Intern creates "<< "RobotomyRequestForm"<<std::endl;
        return (new RobotomyRequestForm(target));
    case 2:
      std::cout<<"Intern creates "<< "PresidentialPardonForm"<<std::endl;
        return (new PresidentialPardonForm(target));
    default:
        throw Intern::NoSuchForm();
    }
 }