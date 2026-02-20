#include "Bureaucrat.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);      
        Bureaucrat bob("Bob", 138);        
        Bureaucrat charlie("Charlie", 50);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        std::cout << "\n===== ShrubberyCreationForm =====\n";
        bob.signForm(shrub);         // ok (sign grade 145)
        bob.executeForm(shrub);      // fail (exec grade 137, Bob has 140)
        alice.executeForm(shrub);
        //charlie.executeForm(shrub);    // success (Alice has grade 1)

        std::cout << "\n===== RobotomyRequestForm =====\n";
        charlie.signForm(robot);     // ok (sign grade 72)
        charlie.executeForm(robot);  // fail (exec grade 45, Charlie has 50)
        alice.executeForm(robot);    // success (random success/fail 50%)

        std::cout << "\n===== PresidentialPardonForm =====\n";
        charlie.signForm(pardon);    // fail (needs 25, Charlie has 50)
        alice.signForm(pardon);      // success
        alice.executeForm(pardon);   // success

    } catch (std::exception &e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}

