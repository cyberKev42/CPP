
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) {
    std::cout << "FragTraps default constructor called" << std::endl;
    this->_name = name;
    this->_hp = 100;
    this->_ep = 100;
    this->_atk = 30;
}
FragTrap::FragTrap(ScavTrap& original) {
    std::cout << "FragTraps copy constructor called" << std::endl;
    *this = original;
}
FragTrap::~FragTrap() {
    std::cout << "FragTraps destructor called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& S) {
    if (this != &S) {
        _name = C._name;
        _hp = C._hp;
        _ep = C._ep;
        _atk = C._atk;
    }
    return *this;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap is now high fiving guys" << std::endl;
}