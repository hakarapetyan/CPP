#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"
#include <cstdlib>

class Bureaucrat;

class AForm
{
    private:
    std::string const name;
    bool is_signed;
    const int required_to_sign;
    const int required_to_execute;
    
    public:
    AForm();
    virtual ~AForm();
    AForm(const AForm &copy);
    AForm(std::string const name, bool is_signed, const int required_to_sign, const int required_to_execute);
    AForm(std::string const name, const int required_to_sign, const int required_to_execute);
    AForm& operator=(const AForm &other);
    bool get_isSigned() const;
    const int &get_toSigned() const;
    const int &get_toExecute() const;
    std::string const &get_name() const;
    void beSigned(Bureaucrat &bur);
    void execute(Bureaucrat const & executor) const;
    virtual void execute_action() const=0;
    virtual std::string const& gettarget() const=0;

    
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

    class FormIsNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};
std::ostream& operator<<(std::ostream& out, const AForm& other);
#endif