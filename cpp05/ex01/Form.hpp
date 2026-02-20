#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
    std::string const name;
    bool is_signed;
    const int required_to_sign;
    const int required_to_execute;

    public:
    Form();
    ~Form();
    Form(const Form &copy);
    Form(std::string const name, bool is_signed, const int required_to_sign, const int required_to_execute);
    Form& operator=(const Form &other);
    const bool &get_isSigned() const;
    const int &get_toSigned() const;
    const int &get_toExecute() const;
    std::string const &get_name() const;
    void beSigned(Bureaucrat &bur);
    
    public:
    class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};
std::ostream& operator<<(std::ostream& out, const Form& other);
#endif