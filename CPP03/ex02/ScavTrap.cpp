/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:00:57 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/13 17:29:44 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "ScavTraps default constructor called" << std::endl;
    this->_name = "";
    this->_hp = 100;
    this->_ep = 50;
    this->_atk = 20;
}
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
        _name = S._name;
        _hp = S._hp;
        _ep = S._ep;
        _atk = S._atk;
    }
    return *this;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->_ep > 0 && this->_hp > 0) {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_atk << " damage" << std::endl;
        this->_ep--;
    }
    else
        std::cout << "ScavTrap " << this->_name << " has not enough HP or EP to attack (" << this->_hp << "HP/" << this->_ep << "EP)" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
    this->_hp -= amount;
     if (this->_hp <= 0)
        this->_hp = 0;
    std::cout << "ScavTrap " << this->_name << " takes " << amount << " damage (" << this->_hp << "HP/" << this->_ep << "EP)" << std::endl;
    if (this->_hp == 0)
        std::cout << "ScavTrap " << this->_name << " has 0HP left" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (this->_ep > 0 && this->_hp > 0) {
        this->_ep--;
        this->_hp += amount;
        if (this->_hp > 100)
            this->_hp = 100;
        std::cout << "ScavTrap " << this->_name << " repaired himself: +" << amount << "HP (" << this->_hp << "HP/" << this->_ep << "EP)" << std::endl;
    }
    else if (this->_ep == 0 || this->_hp == 0)
        std::cout << "ScavTrap " << this->_name << " has not enough HP or EP to repair himself (" << this->_hp << "HP/" << this->_ep << "EP)" << std::endl;
}