/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:14:29 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/03 15:35:58 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){
	this->name = "";
}
Zombie::Zombie(std::string name){
	this->name = name;
	announce();	
}
Zombie::~Zombie(){
	std::cout << this->name << " dies" << std::endl;
}

void Zombie::announce(){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// std::string Zombie::getName(){
// 	return name;
// }

Zombie* Zombie::zombieHorde(int N, std::string name){
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++){
		horde[i].name = name;
		horde[i].announce();	
	}
	return horde;
}