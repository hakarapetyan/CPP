#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm",72,45),target("default")
{
    std::cout << "RobotomyRequestForm Default Constructor called for " << this->gettarget() << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called for " << this->gettarget()<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm (const RobotomyRequestForm &other):AForm("RobotomyRequestForm",72,45),target(other.gettarget())
{
    std::cout << "RobotomyRequestForm Copy Constructor called for " << this->gettarget() << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string const name):AForm("RobotomyRequestForm",72,45),target(name)
{
     std::cout << "RobotomyRequestForm Name Constructor called for " << this->gettarget() << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm assignation operator called for " << this->gettarget() << std::endl;
    if(this!=&other)
    {
        AForm::operator=(other);
    }
    return(*this);
}

std::string const RobotomyRequestForm:: gettarget() const
{
    return(this->target);
}
void RobotomyRequestForm::execute_action()const
{
    std::cout<<"Some drilling noices" << std::endl;
    if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " robotomy failed." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& other)
{
    out << "Name: "<<other.get_name() << "issigned" << other.get_isSigned()<<"SignGrade:"<<other.get_toSigned()<<"ExecuteGrade: "<<other.get_toExecute()<<"\n";
    return out;
}