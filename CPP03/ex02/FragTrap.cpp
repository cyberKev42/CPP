/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:32:53 by kevin             #+#    #+#             */
/*   Updated: 2025/02/08 16:05:43 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTraps default constructor called" << std::endl;
    this->_name = name;
    this->_hp = 100;
    this->_ep = 100;
    this->_atk = 30;
}
FragTrap::FragTrap(FragTrap& original) {
    std::cout << "FragTraps copy constructor called" << std::endl;
    *this = original;
}
FragTrap::~FragTrap() {
    std::cout << "FragTraps destructor called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& F) {
    if (this != &F) {
        _name = F._name;
        _hp = F._hp;
        _ep = F._ep;
        _atk = F._atk;
    }
    return *this;
}

void FragTrap::guardGate() {
    std::cout << "FragTrap is now in Gate keeper mode" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->_ep > 0 && this->_hp > 0) {
        std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_atk << " damage" << std::endl;
        this->_ep--;
    }
    else
        std::cout << "FragTrap " << this->_name << " has not enough HP or EP to attack (" << this->_hp << "HP/" << this->_ep << "EP)" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
    this->_hp -= amount;
     if (this->_hp <= 0)
        this->_hp = 0;
    std::cout << "FragTrap " << this->_name << " takes " << amount << " damage (" << this->_hp << "HP/" << this->_ep << "EP)" << std::endl;
    if (this->_hp == 0)
        std::cout << "FragTrap " << this->_name << " has 0HP left" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
    if (this->_ep > 0 && this->_hp > 0) {
        this->_ep--;
        this->_hp += amount;
        if (this->_hp > 100)
            this->_hp = 100;
        std::cout << "FragTrap " << this->_name << " repaired himself: +" << amount << "HP (" << this->_hp << "HP/" << this->_ep << "EP)" << std::endl;
    }
    else if (this->_ep == 0 || this->_hp == 0)
        std::cout << "FragTrap " << this->_name << " has not enough HP or EP to repair himself (" << this->_hp << "HP/" << this->_ep << "EP)" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->_name << " requests High Five from other ClapTraps" << std::endl;
}