
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    ClapTrap C1("Larry");
    ScavTrap S1("Hank");

    C1.attack("Hank");
    C1.takeDamage(4);
    C1.beRepaired(2);

    S1.attack("Larry");
    S1.takeDamage(25);
    S1.beRepaired(10);
    S1.guardGate();

}