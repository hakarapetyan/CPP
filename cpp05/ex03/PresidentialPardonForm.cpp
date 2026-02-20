#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm",25,5),target("default")
{
    std::cout << "PresidentialPardonForm Default Constructor called "  << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor called " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm (const PresidentialPardonForm &other):AForm("PresidentialPardonForm",25,5),target(other.gettarget())
{
    std::cout << "PresidentialPardonForm Copy Constructor called "  << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string const name):AForm("PresidentialPardonForm",25,5),target(name)
{
     std::cout << "PresidentialPardonForm Name Constructor called "  << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm assignation operator called " << this->gettarget() << std::endl;
    if(this!=&other)
    {
        AForm::operator=(other);
    }
    return(*this);
}

std::string const& PresidentialPardonForm:: gettarget() const
{
    return(this->target);
}

void PresidentialPardonForm::execute_action() const
{
    std::cout<<gettarget()<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
}

