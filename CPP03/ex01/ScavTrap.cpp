/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:00:57 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/23 19:00:58 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        _name = S._name;
        _hp = S._hp;
        _ep = S._ep;
        _atk = S._atk;
    }
    return *this;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTraps is now in Gate keeper mode" << std::endl;
}