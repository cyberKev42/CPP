#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
    std::cout << "Default constructor called" << std::endl;
    this->_name = _name;
    this->_hp = 10;
    this->_ep = 10;
    this->_atk = 0;
}
ClapTrap::ClapTrap(ClapTrap& original) {
    std::cout << "Copy constructor called" << std::endl;
    *this = original;
}
ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& C) {
    if (this != &C) {
        _name = C._name;
        _hp = C._hp;
        _ep = C._ep;
        _atk = C._atk;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_ep > 0 && this->_hp > 0)
        std::cout << "ClapTrap attacks " << target << ", causing " << this->_atk << " damage" << std::endl;
    else
        std::cout << "ClapTrap has not enough HP or EP to attack (" << this->_hp << "HP/" << this->_ep << "EP)" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    this->_hp -= amount;
    std::cout << "ClapTrap takes " << amount << " damage" << std::endl;
    if (this->_hp <= 0) {
        this->_hp = 0;
        std::cout << "ClapTrap has 0HP left" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_ep > 0 && this->_hp > 0) {
        this->_ep -= 1;
        this->_hp += amount;
        if (this->_hp > 10)
            this->_hp = 10;
        std::cout << "ClapTrap repaired himself: +" << amount << "HP" << std::endl;
    }
    if (this->_ep == 0)
        std::cout << "ClapTrap has not enough HP or EP to attack (" << this->_hp << "HP/" << this->_ep << "EP)" << std::endl;
}