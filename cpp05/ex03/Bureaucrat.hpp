#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
    std::string const name;
    int grade;

    public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat(std::string const name, int grade);
    Bureaucrat& operator=(const Bureaucrat &other);
    int getGrade() const;
    std::string const getName() const;
    void Increment();
    void Decrement();
    void signForm(AForm &f);
    void executeForm(AForm const & form) const;

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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);
#endif