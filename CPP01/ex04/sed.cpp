/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:18:16 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/04 19:16:29 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

Sed::Sed(std::string filename){
	this->_inputFile = filename;
	this->_outputFile = filename.append(".replace");
}
Sed::~Sed(){
}

void Sed::replaceStr(std::string str1, std::string str2){
	// read inputFile
	std::ifstream ifs (this->_inputFile);
	if (ifs.is_open())
	{
		std::string buf;
		
	} else {
		std::cout << "Cannot read input file!" << std::endl;
	}
	// replace strings
	// store in outputFile
	
}