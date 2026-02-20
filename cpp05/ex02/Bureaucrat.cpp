#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("default"),grade(150)
{
    std::cout << "Bureaucrat Default Constructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat (const Bureaucrat &other):name(other.name),grade(other.grade)
{
    std::cout << "Bureaucrat Copy Constructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}
Bureaucrat::Bureaucrat(std::string const name, int grade):name(name),grade(grade)
{
    if(this->grade>150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    if(this->grade<1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
     std::cout << "Bureaucrat Name Constructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat assignation operator called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
    if(this!=&other)
    {
        this->grade=other.grade;
    }
    return(*this);
}

int Bureaucrat::getGrade() const
{
    return(this->grade);
}
std::string const Bureaucrat::getName() const
{
    return(this->name);
}
void Bureaucrat::Increment()
{
    if(this->grade<=1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
}
void Bureaucrat::Decrement()
{
    if(this->grade>=150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other) {
    out << other.getName() << ", bureaucrat grade " << other.getGrade()<<"\n";
    return out;
}

void Bureaucrat::signForm(AForm &f)
{
   try
	{
		f.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << name << " couldn't sign " << f.get_name() << " because " << e.what() << std::endl;
		return;
	}
	std::cout << name << " signed " << f.get_name() << std::endl;
}
void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cout<<name<<" couldn't execute " <<form.get_name()<<" because "<< e.what() << '\n';
        return;
    }
    std::cout << name << " executed " << form.get_name() << std::endl;
}