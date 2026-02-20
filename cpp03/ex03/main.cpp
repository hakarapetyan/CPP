#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== Creating DiamondTrap ===" << std::endl;
    DiamondTrap diamond("BeastBot");

    std::cout << "\n=== Calling whoAmI ===" << std::endl;
    diamond.whoAmI(); // Should show both DiamondTrap's and ClapTrap's names

    std::cout << "\n=== Attacking target ===" << std::endl;
    diamond.attack("TrainingDummy"); // Uses ScavTrap::attack()

    std::cout << "\n=== Taking damage ===" << std::endl;
    diamond.takeDamage(40); // Inherited from ClapTrap

    std::cout << "\n=== Repairing ===" << std::endl;
    diamond.beRepaired(25); // Inherited from ClapTrap

    std::cout << "\n=== Finished ===" << std::endl;

    return 0;
}