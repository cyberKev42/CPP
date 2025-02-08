#include "ClapTrap.hpp"

int main() {

    ClapTrap C1("Larry");
    ClapTrap C2("Hank");

    C1.attack("Hank");
    C1.takeDamage(4);
    C1.takeDamage(4);
    C1.takeDamage(4);
    C1.beRepaired(2);
    C1.beRepaired(2);
    C1.beRepaired(2);

	C2.attack("Larry");
    C2.takeDamage(6);
    C2.beRepaired(3);
}