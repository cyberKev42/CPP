/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:27:28 by kbrauer           #+#    #+#             */
/*   Updated: 2024/10/12 14:43:41 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

class Contact {
	private:
		int			index;
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string secret;
	public:
		int			get_index();
		void		set_index(int index);
		std::string get_first_name();
		void		set_first_name(std::string first_name);
		std::string get_last_name();
		void		set_last_name(std::string last_name);
		std::string get_nick_name();
		void		set_nick_name(std::string nick_name);
		std::string get_phone_number();
		void		set_phone_number(std::string phone_number);
		std::string get_secret();
		void		set_secret(std::string secret);	
		
};

#endif