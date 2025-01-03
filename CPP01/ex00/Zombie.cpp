/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:56:16 by kbrauer           #+#    #+#             */
/*   Updated: 2024/10/12 15:48:28 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name){
	this->name = name;
	announce();	
}
Zombie::~Zombie(){
	std::cout << name << " dies" << std::endl;
}

void Zombie::announce(){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

