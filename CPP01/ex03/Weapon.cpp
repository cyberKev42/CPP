/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:00:12 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/03 16:19:49 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>
#include <string>


Weapon::Weapon(std::string type){
	setType(type);
}
Weapon::~Weapon(){
}

const std::string& Weapon::getType(){
	return this->type;
}

void Weapon::setType(std::string type){
	this->type = type;
}
