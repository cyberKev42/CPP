
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : ClapTrap {
private:
public:
    ScavTrap(std::string name);
    ScavTrap(ScavTrap& original);
    ~ScavTrap();
    ScavTrap& operator=(const ScavTrap& S);
    void guardGate();
}

#endif