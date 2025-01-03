/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:00:04 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/03 16:05:13 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(){
}
HumanB::~HumanB(){
}

HumanB::HumanB(std::string name){
	this->name = name;
}

void HumanB::attack(){
	std::cout << name << " attacks with their weapon " << weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon) {
	this->weapon = weapon;
}
