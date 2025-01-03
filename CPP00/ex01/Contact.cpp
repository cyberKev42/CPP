/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:03:16 by kbrauer           #+#    #+#             */
/*   Updated: 2024/10/12 14:19:56 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int Contact::get_index(){
	return index;
}
void Contact::set_index(int index){
	this->index = index;
}

std::string Contact::get_first_name(){
	return first_name;
}
void Contact::set_first_name(std::string first_name){
	this->first_name = first_name;
}

std::string Contact::get_last_name(){
	return last_name;
}
void Contact::set_last_name(std::string last_name){
	this->last_name = last_name;
}

std::string Contact::get_nick_name(){
	return nick_name;
}
void Contact::set_nick_name(std::string nick_name){
	this->nick_name = nick_name;
}

std::string Contact::get_phone_number(){
	return phone_number;
}
void Contact::set_phone_number(std::string phone_number){
	this->phone_number = phone_number;
}

std::string Contact::get_secret(){
	return secret;
}
void Contact::set_secret(std::string secret){
	this->secret = secret;
}