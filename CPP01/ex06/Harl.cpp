/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:02:55 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/10 17:17:33 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
}
Harl::~Harl(){
}

void Harl::debug(void){
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple- \
pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info(void){
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger! If you did, I wouldn’t be \
asking for more!" << std::endl << std::endl;
}

void Harl::warning(void){
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since \
last month." << std::endl << std::endl;
}

void Harl::error(void){
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." \
	<< std::endl << std::endl;
}

void Harl::complain(std::string level){
	std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i;
	for (i = 0; i < 4; i++){
		if (level == arr[i])
			break;
	}

	switch (i)
	{
	case 0:
		(this->*ptr[0])();
	case 1:
		(this->*ptr[1])();
	case 2:
		(this->*ptr[2])();
	case 3:{
		(this->*ptr[3])();
		break;
	}
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
