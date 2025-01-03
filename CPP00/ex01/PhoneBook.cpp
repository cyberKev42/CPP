/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:37:27 by kbrauer           #+#    #+#             */
/*   Updated: 2024/10/12 14:43:31 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <cstring>

int PhoneBook::add(){
	std::string tmp_string;
	contacts[new_entry].set_index(new_entry + 1);
	std::cout << "\nAdd contact details" << std::endl;
	while (1){
		std::cout << "First Name:" << std::endl;
		std::getline(std::cin, tmp_string);
		contacts[new_entry].set_first_name(tmp_string);
		if (std::cin.eof())
			return 1;
		switch (check_name(contacts[new_entry].get_first_name())) {
			case 0:
				goto goto_label1;
			case 1:
				std::cout << "Only letters and space allowed!" << std::endl;
				break;
			case 2:
				std::cout << "Space at beginning not allowed ;)" << std::endl;
				break;
		}
	}
	goto_label1:
	while (1){
		std::cout << "Last Name:" << std::endl;
		std::getline(std::cin, tmp_string);
		contacts[new_entry].set_last_name(tmp_string);
		if (std::cin.eof())
			return 1;
		switch (check_name(contacts[new_entry].get_last_name())) {
			case 0:
				goto goto_label2;
			case 1:
				std::cout << "Only letters and space allowed!" << std::endl;
				break;
			case 2:
				std::cout << "Space at beginning not allowed ;)" << std::endl;
				break;
		}
	}
	goto_label2:
	while (1){
		std::cout << "Nickname:" << std::endl;
		std::getline(std::cin, tmp_string);
		contacts[new_entry].set_nick_name(tmp_string);
		if (std::cin.eof())
			return 1;
		switch (check_nickname(contacts[new_entry].get_nick_name())) {
			case 0:
				goto goto_label3;
			case 1:
				std::cout << "Only letters, numbers and space allowed!" << std::endl;
				break;
			case 2:
				std::cout << "Space/number at beginning not allowed ;)" << std::endl;
				break;
		}
	}
	goto_label3:
	while (1){
		std::cout << "Phone number:" << std::endl;
		std::getline(std::cin, tmp_string);
		contacts[new_entry].set_phone_number(tmp_string);
		if (std::cin.eof())
			return 1;
		switch (check_phone_number(contacts[new_entry].get_phone_number())) {
			case 0:
				goto goto_label4;
			case 1:
				std::cout << "Only numbers allowed!" << std::endl;
				break;
		}
	}
	goto_label4:
	while (1){
		std::cout << "What's your darkest secret?" << std::endl;
		std::getline(std::cin, tmp_string);
		contacts[new_entry].set_secret(tmp_string);
		if (std::cin.eof())
			return 1;
		switch (check_nickname(contacts[new_entry].get_secret())) {
			case 0:
				goto goto_label5;
			case 1:
				std::cout << "Only letters, numbers and space allowed!" << std::endl;
				break;
			case 2:
				std::cout << "Space/number at beginning not allowed ;)" << std::endl;
				break;
		}
	}
	goto_label5:
	new_entry++;
	if (new_entry == 8) {
		phonebook_full = true;
		new_entry = 0;
	}
	return 0;
}

int PhoneBook::search(){
	goto_label7:
	std::cout	<< blue 
				<< " ___________________________________________"  << std::endl
				<< "|          |          |          |          |" << std::endl
				<< "|" 
				<< magenta << "     Index" << blue << "|"
				<< magenta << "First Name" << blue << "|"
				<< magenta << " Last Name" << blue << "|"
				<< magenta << "  Nickname" << blue << "|" << std::endl
				<< "|__________|__________|__________|__________|" << std::endl
				<< "|          |          |          |          |" << std::endl;
	int max = new_entry;
	if (phonebook_full)
		max = 8;
	for (int i = 0; i < max; i++){
		std::cout	<< "|" << yellow << std::setw(10) << contacts[i].get_index() << blue;
		if (contacts[i].get_first_name().length() > 10){
			std::cout << "|" << magenta << std::setw(9) << contacts[i].get_first_name().substr(0, 9) << "." << blue;
		} else {
			std::cout << "|" << magenta << std::setw(10) << contacts[i].get_first_name() << blue;
		}
		if (contacts[i].get_last_name().length() > 10){
			std::cout << "|" << magenta << std::setw(9) << contacts[i].get_last_name().substr(0, 9) << "." << blue;
		} else {
			std::cout << "|" << magenta << std::setw(10) << contacts[i].get_last_name() << blue;
		}
		if (contacts[i].get_nick_name().length() > 10){
			std::cout << "|" << magenta << std::setw(9) << contacts[i].get_nick_name().substr(0, 9) << "." << blue;
		} else {
			std::cout << "|" << magenta << std::setw(10) << contacts[i].get_nick_name() << blue;
		}
		std::cout << "|" << std::endl;
	}
	std::cout	<< "|__________|__________|__________|__________|"  << reset << std::endl;

	
	std::string tmp_str;
	std::cout << "\nType Index# to show contact information" << std::endl;
	while (1) {
		std::getline(std::cin, tmp_str);
		if (std::cin.eof())
			return 1;
		switch (check_index(tmp_str)) {
			case 5:
				goto goto_label7;
			case 4:
				goto goto_label6;
			case 3:
				break;
			case 1:
				std::cout << "Only numbers allowed!" << std::endl;
				break;
			case 2:
				std::cout << "Index can only be single digit!" << std::endl;
				break;
			case 0:
				PhoneBook::print_contact(atoi(tmp_str.c_str()) - 1);
		}
		std::cout << "\nType Index# to show contact information, \"t\" to show contact " << underline "t" << reset;
		std::cout << "able or \"x\" to e" << underline << "x" << reset << "it SEARCH" << std::endl;
	}
	goto_label6:

	return 0;
}

int PhoneBook::exit(){
	std::cout << "Deleting all contacts.....100%\nDestroying PhoneBook" << std::endl;
	return 1;
}

int	main()	{

	PhoneBook 	phonebook;
	std::string input;

	std::cout << "Welcome to PHONEBOOK!\nDo you want to \"ADD\" a contact, \"SEARCH\" for a contact or \"EXIT\" the program?" << std::endl;
	while (!std::cin.eof())
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			return phonebook.exit();
		if (input.compare("") == 0) {
			std::cout << "Do you want to \"ADD\" a contact, \"SEARCH\" for a contact or \"EXIT\" the program?" << std::endl;
			continue;
		}
		if (input.compare("ADD") == 0){
			if (phonebook.add())
				return phonebook.exit();
			else {
				std::cout << "\nDo you want to \"ADD\" a contact, \"SEARCH\" for a contact or \"EXIT\" the program?" << std::endl;
				continue;
			}
		}
		else if (input.compare("SEARCH") == 0) {
			if (phonebook.search())
				return phonebook.exit();
			std::cout << "\nDo you want to \"ADD\" a contact, \"SEARCH\" for a contact or \"EXIT\" the program?" << std::endl;
			continue;
		}
		else if (input.compare("EXIT") == 0)
			return phonebook.exit();
		std::cout << "\nYou can't just type random sh*t! Please stick to the commands\n\"ADD\", \"SEARCH\" and \"EXIT\"" << std::endl;
	}


}
