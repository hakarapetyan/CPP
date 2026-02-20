#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "\n--- CONSTRUCTION PHASE ---\n";
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavy");
	FragTrap frag("Fraggy");

	std::cout << "\n--- BASIC ATTACKS ---\n";
	clap.attack("Scavy");
	scav.attack("Fraggy");
	frag.attack("Clappy");

	std::cout << "\n--- DAMAGE & REPAIR ---\n";
	clap.takeDamage(3);
	clap.beRepaired(5);
	frag.takeDamage(50);
	frag.beRepaired(25);

	std::cout << "\n--- SPECIAL ABILITIES ---\n";
	scav.guardGate();
	frag.highFivesGuys();

	std::cout << "\n--- COPY & ASSIGNMENT TEST ---\n";
	FragTrap fragCopy(frag);   
	FragTrap fragAssigned;
	fragAssigned = frag;   

	std::cout << "\n--- DESTRUCTION PHASE (on exit) ---\n";
	return 0;
}