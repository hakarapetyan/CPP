#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Form f1("TaxForm", false, 50, 25);
        Form f2("SecretForm", false, 1, 1);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        try {
            Form bad("BadForm", false, 160, 20); // too low
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        try {
            Form bad2("TooHighForm", false, 0, 5); // too high
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        Bureaucrat bob("Bob", 40);
        Bureaucrat jim("Jim", 100);

        std::cout << bob << std::endl;
        std::cout << jim << std::endl;

        std::cout << "\nTrying to sign f1 with Jim (grade 100, required 50) → should fail" << std::endl;
        jim.signForm(f1);

        std::cout << "\nTrying to sign f1 with Bob (grade 40, required 50) → should succeed" << std::endl;
        bob.signForm(f1);

        std::cout << f1 << std::endl;

    } catch (std::exception &e) {
        std::cout << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}


