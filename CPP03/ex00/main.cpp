

#include "ClapTrap.hpp"

void main() {

    ClapTrap C1("Larry");
    ClapTrap C2("Hank");

    C1.attack("Hank");
    C1.takeDamage(4);
    C1.beRepaired(2);

}