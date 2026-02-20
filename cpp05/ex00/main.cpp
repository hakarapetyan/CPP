#include "Bureaucrat.hpp"
int main()
{
    try
    {
        Bureaucrat ob2;
        Bureaucrat ob3("Petros", 56);
        Bureaucrat ob(ob2);
        std::cout<<ob2;
        std::cout<<ob3;
        ob2 = ob;
        std::cout<<ob2;
        std::cout<<ob;
        ob2.Decrement();
        ob2.Increment();
        ob2.Increment();
        ob2.Increment();
        ob2.Increment();
        ob2.Decrement();
        ob2.Decrement();
        std::cout<<ob2;
        std::cout<<ob;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout<< e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << '\n';
    }
}