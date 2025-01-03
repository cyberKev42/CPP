/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:00:00 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/03 16:05:18 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(){
}
HumanA::HumanA(std::string name, Weapon weapon){
	this->name = name;
	this->weapon = weapon;
}
HumanA::~HumanA(){	
}


void HumanA::attack(){
	std::cout << name << " attacks with their weapon " << weapon.getType() << std::endl;
}
