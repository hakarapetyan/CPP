#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "Form.hpp"

class Form;

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
    void signForm(Form &f);

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