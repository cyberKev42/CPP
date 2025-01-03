/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:59:50 by kbrauer           #+#    #+#             */
/*   Updated: 2024/10/12 14:34:06 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int check_name(std::string str){
	if (str[0] == 0)
		return 3;
	if (str[0] == 32)
		return 2;
	for (int i = 0; str[i]; i++){
		if (!(isalpha(str[i]) || str[i] == 32))
			return 1;
	}
	return 0;
}

int check_nickname(std::string str){
	if (str[0] == 0)
		return 3;
	if (str[0] == 32 || (str[0] >= 48 && str[0] <= 57))
		return 2;
	for (int i = 0; str[i]; i++){
		if (!(isalnum(str[i]) || str[i] == 32))
			return 1;
	}
	return 0;
}

int check_phone_number(std::string str){
	if (str[0] == 0)
		return 3;
	for (int i = 0; str[i]; i++){
		if (!(isdigit(str[i])))
			return 1;
	}
	return 0;
}

int check_index(std::string str){
	if (str[0] == 'x' && str[1] == 0)
		return 4;
	if (str[0] == 't' && str[1] == 0)
		return 5;
	if (str[0] == 0)
		return 3;
	for (int i = 0; str[i]; i++){
		if (!(isdigit(str[i])))
			return 1;
		if (i == 1)
			return 2;
	}
	return 0;
}

int PhoneBook::print_contact(int i){
	if (i < 0 || i + 1 == 9){
		if (!phonebook_full && new_entry == 0)
			std::cout	<< "\nNo contact added to PhoneBook yet." << std::endl;
		else
			std::cout	<< "\nInvalid index, only 8 contacts possible." << std::endl;
		return 1;
	}
	if (!phonebook_full && new_entry == 0){
		std::cout	<< "\nNo contact added to PhoneBook yet." << std::endl;
		return 1;
	}
	if ((phonebook_full && i > 8) || (!phonebook_full && i + 1 > new_entry)){
		std::cout	<< "\nNo contact at this index." << std::endl;
		return 1;
	}
	std::cout	<< "\nFirst Name:     "   << contacts[i].get_first_name() << std::endl
				<< "Last Name:      "    << contacts[i].get_last_name() << std::endl
				<< "Nickname:       "     << contacts[i].get_nick_name() << std::endl
				<< "Phone Number:   " << contacts[i].get_phone_number() << std::endl
				<< "Darkest secret: " << contacts[i].get_secret() << std::endl;
	return 0;
}