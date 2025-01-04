/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:00:04 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/04 17:29:38 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(){
}
HumanB::HumanB(std::string name){
	this->_name = name;
	this->_weapon = NULL;
}
HumanB::~HumanB(){
}

void HumanB::attack(){
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}
