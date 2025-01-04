/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:00:00 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/04 17:29:36 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon)
{
	this->_name = name;
}
HumanA::~HumanA(){
}


void HumanA::attack(){
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
