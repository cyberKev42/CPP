
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) {
    std::cout << "ScavTraps default constructor called" << std::endl;
    this->_name = name;
    this->_hp = 100;
    this->_ep = 50;
    this->_atk = 20;
}
ScavTrap::ScavTrap(ScavTrap& original) {
    std::cout << "ScavTraps copy constructor called" << std::endl;
    *this = original;
}
ScavTrap::~ScavTrap() {
    std::cout << "ScavTraps destructor called" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& S) {
    if (this != &S) {
        _name = C._name;
        _hp = C._hp;
        _ep = C._ep;
        _atk = C._atk;
    }
    return *this;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTraps is now in Gate keeper mode" << std::endl;
}