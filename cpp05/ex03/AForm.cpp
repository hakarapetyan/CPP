#include "AForm.hpp"

AForm::AForm():name("default"),is_signed(false),required_to_sign(150),required_to_execute(150)
{
    std::cout << "AForm Default Constructor called for " << this->get_name()<<std::endl;
}
AForm::~AForm()
{
    std::cout << "AForm Destructor called for " << this->get_name()<<std::endl;
}
AForm::AForm (const AForm &other):name(other.name),is_signed(other.is_signed),required_to_sign(other.required_to_sign),required_to_execute(other.required_to_execute)
{
    std::cout << "AForm Copy Constructor called for " << this->get_name()<<std::endl;
}
AForm::AForm(std::string const name, bool is_signe,const int to_signe,const int to_execute):name(name),is_signed(is_signe),required_to_sign(to_signe),required_to_execute(to_execute)
{
     std::cout << "AForm Name Constructor called for " << this->get_name()<<std::endl;
     if(required_to_sign > 150 || required_to_execute > 150)
        throw AForm::GradeTooLowException();
    else if(required_to_execute < 1 || required_to_sign < 1)
        throw AForm::GradeTooHighException();
    
}
AForm::AForm(std::string const name, const int to_signe,const int to_execute):name(name),required_to_sign(to_signe),required_to_execute(to_execute)
{
    std::cout << "AForm Name Constructor called for " << this->get_name()<<std::endl;
     if(required_to_sign > 150 || required_to_execute > 150)
        throw AForm::GradeTooLowException();
    else if(required_to_execute < 1 || required_to_sign < 1)
        throw AForm::GradeTooHighException();
}
AForm& AForm::operator=(const AForm &other)
{
    std::cout << "AForm assignation operator called for " << this->get_name()<<std::endl;
    if(this!=&other)
    {
    this->is_signed=other.is_signed;
    }
    return(*this);
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}
const char* AForm::FormIsNotSignedException::what() const throw(){
    return "Form is not signed";
}
void AForm::beSigned(Bureaucrat &bur)
{
    if(bur.getGrade()<=this->required_to_sign)
    {
        this->is_signed=true;
    }
    else
        throw AForm::GradeTooLowException();
}

bool AForm:: get_isSigned() const{return(is_signed);}
const int &AForm:: get_toSigned() const{return(required_to_sign);}
const int &AForm::get_toExecute() const{return(required_to_execute);}
std::string const &AForm:: get_name() const{return(name);}

void AForm::execute(Bureaucrat const & executor) const
{
    if(this->required_to_execute < executor.getGrade())
    {
        throw AForm::GradeTooLowException();
    }
    if(this->is_signed == false)
    {
        throw AForm::FormIsNotSignedException();
    }
    else
    {
        execute_action();
    }
}

std::ostream& operator<<(std::ostream& out, const AForm& other)
{
    out << "Name: "<<other.get_name() <<" Target: "<<other.gettarget()<< " is signed " << other.get_isSigned()<<" SignGrade: "<<other.get_toSigned()<<" ExecuteGrade: "<<other.get_toExecute()<<"\n";
    return out;
}