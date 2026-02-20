
#include "ScavTrap.hpp"

int main()
{
	std::cout << "\n--- CONSTRUCTORS ---\n";
	ScavTrap scav1("Guardian");
	ClapTrap clap1("Worker");

	std::cout << "\n--- SCAVTRAP GUARD MODE ---\n";
	scav1.guardGate();

	std::cout << "\n--- ENERGY EXHAUSTION TEST ---\n";
	for (int i = 0; i < 51; ++i) {
		scav1.attack("an intruder");
	}

	std::cout << "\n--- OVER-REPAIR & DAMAGE ---\n";
	clap1.takeDamage(5);
	clap1.beRepaired(15);

	clap1.takeDamage(20);
	clap1.attack("anyone");
	clap1.beRepaired(5);

	std::cout << "\n--- COPY CONSTRUCTORS & ASSIGNMENT ---\n";
	ScavTrap scav2 = scav1;
	ScavTrap scav3("Temp");
	//scav3 = scav1; 

	std::cout << "\n--- DESTRUCTORS (on exit) ---\n";
	return 0;
}