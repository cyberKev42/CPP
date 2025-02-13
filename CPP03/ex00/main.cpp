#include "ClapTrap.hpp"

int main() {

    ClapTrap C1("Larry");
    ClapTrap C2("Hank");
	ClapTrap C2_copy(C2);

	std::cout << std::endl;

    C1.attack("Hank");
    C1.takeDamage(2);
    C1.takeDamage(1);
    // C1.takeDamage(8);
    C1.beRepaired(2);
    C1.beRepaired(2);
    C1.beRepaired(2);

	std::cout << std::endl;

	C2.attack("Larry");
    C2.takeDamage(6);
    C2.beRepaired(3);

	std::cout << std::endl;

	C2_copy.attack("Larry_copy");
    C2_copy.takeDamage(6);
    C2_copy.beRepaired(3);

	std::cout << std::endl;
}