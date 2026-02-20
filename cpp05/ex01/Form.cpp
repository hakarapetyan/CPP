#include "Form.hpp"

Form::Form():name("default"),is_signed(false),required_to_sign(150),required_to_execute(150)
{
    std::cout << "Form Default Constructor called for " << this->get_name()<<std::endl;
}
Form::~Form()
{
    std::cout << "Form Destructor called for " << this->get_name()<<std::endl;
}
Form::Form (const Form &other):name(other.name),is_signed(other.is_signed),required_to_sign(other.required_to_sign),required_to_execute(other.required_to_execute)
{
    std::cout << "Form Copy Constructor called for " << this->get_name()<<std::endl;
}
Form::Form(std::string const name, bool is_signed,const int to_signe,const int to_execute):name(name),is_signed(is_signed),required_to_sign(to_signe),required_to_execute(to_execute)
{
     std::cout << "Form Name Constructor called for " << this->get_name()<<std::endl;
     if(required_to_sign > 150 || required_to_execute > 150)
        throw Form::GradeTooLowException();
    else if(required_to_execute < 1 || required_to_sign < 1)
        throw Form::GradeTooHighException();
    
}
Form& Form::operator=(const Form &other)
{
    std::cout << "Form assignation operator called for " << this->get_name()<<std::endl;
    if(this!=&other)
    {
        this->is_signed=other.is_signed;
    }
    return(*this);
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}
void Form::beSigned(Bureaucrat &bur)
{
    if(bur.getGrade()<=this->required_to_sign)
    {
        this->is_signed=true;
    }
    else
        throw Form::GradeTooLowException();
}

const bool& Form:: get_isSigned() const{return(is_signed);}
const int& Form:: get_toSigned() const{return(required_to_sign);}
const int& Form:: get_toExecute() const{return(required_to_execute);}
const std::string& Form:: get_name() const{return(name);}

std::ostream& operator<<(std::ostream& out, const Form& other)
{
    out << "Name: "<<other.get_name() << " issigned " << other.get_isSigned()<<" SignGrade: "<<other.get_toSigned()<<" ExecuteGrade:  "<<other.get_toExecute()<<"\n";
    return out;
}