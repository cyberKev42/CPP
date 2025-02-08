#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "ClapTraps default constructor called" << std::endl;
    this->_name = "";
    this->_hp = 10;
    this->_ep = 10;
    this->_atk = 0;
}
ClapTrap::ClapTrap(std::string name) {
    std::cout << "Default constructor called" << std::endl;
    this->_name = name;
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
    if (this->_ep > 0 && this->_hp > 0) {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_atk << " damage" << std::endl;
        this->_ep--;
    }
    else
        std::cout << "ClapTrap " << this->_name << " has not enough HP or EP to attack (" << this->_hp << "HP/" << this->_ep << "EP)" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    this->_hp -= amount;
     if (this->_hp <= 0)
        this->_hp = 0;
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage (" << this->_hp << "HP/" << this->_ep << "EP)" << std::endl;
    if (this->_hp == 0)
        std::cout << "ClapTrap " << this->_name << " has 0HP left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_ep > 0 && this->_hp > 0) {
        this->_ep--;
        this->_hp += amount;
        if (this->_hp > 10)
            this->_hp = 10;
        std::cout << "ClapTrap " << this->_name << " repaired himself: +" << amount << "HP (" << this->_hp << "HP/" << this->_ep << "EP)" << std::endl;
    }
    else if (this->_ep == 0 || this->_hp == 0)
        std::cout << "ClapTrap " << this->_name << " has not enough HP or EP to repair himself (" << this->_hp << "HP/" << this->_ep << "EP)" << std::endl;
}