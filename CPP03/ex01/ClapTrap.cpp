/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:49:21 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/23 18:57:41 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
}
ClapTrap::ClapTrap(std::string name) {
    std::cout << "ClapTraps default constructor called" << std::endl;
    this->_name = _name;
    this->_hp = 10;
    this->_ep = 10;
    this->_atk = 0;
}
ClapTrap::ClapTrap(ClapTrap& original) {
    std::cout << "ClapTraps copy constructor called" << std::endl;
    *this = original;
}
ClapTrap::~ClapTrap() {
    std::cout << "ClapTraps destructor called" << std::endl;
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
    _hp -= amount;
    std::cout << "ClapTrap takes " << amount << " damage" << std::endl;
    if (_hp <= 0) {
        _hp = 0;
        std::cout << "ClapTrap has 0HP left" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_ep > 0) {
        _ep -= 1;
        _hp += amount;
        if (_hp > 10)
            _hp = 10;
        std::cout << "ClapTrap repaired himself: +" << amount << "HP" << std::endl;
    }
    if (_ep == 0)
        std::cout << "ClapTrap has not enough EP to repair himself" << std::endl;
}