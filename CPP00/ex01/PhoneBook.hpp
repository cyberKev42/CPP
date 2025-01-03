/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:27:06 by kbrauer           #+#    #+#             */
/*   Updated: 2024/10/12 14:45:33 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

#define red 		"\x1B[31m"
#define blue 		"\x1B[36m"
#define green 		"\x1B[32m"
#define yellow 		"\x1B[33m"
#define magenta 	"\x1B[35m"
#define underline 	"\033[4m"
#define reset 		"\033[0m"

class PhoneBook {
	private:
		Contact contacts[8];
		int 	new_entry = 0;
		bool	phonebook_full = false;
	public:
		int 	add();
		int 	search();
		int 	exit();
		int 	print_contact(int i);
};

int check_name(std::string str);
int check_nickname(std::string str);
int check_phone_number(std::string str);
int check_index(std::string str);

#endif